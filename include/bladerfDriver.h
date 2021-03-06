#include <libbladeRF.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <global.h>
namespace bladerfDriver
{
struct channelConfig
{
    bladerf_channel channel;
    unsigned int frequency;
    unsigned int bandwidth;
    unsigned int samplerate;
    int gain;
};
struct bladerf_data
{
    void **buffers;            /* Transmit buffers */
    size_t num_buffers;        /* Number of buffers */
    size_t samples_per_buffer; /* Number of samples per buffer */
    unsigned int idx;          /* The next one that needs to go out */
};
struct siginfo
{
    struct bladerf *dev;
    struct bladerf_stream *stream;
};
int configureChannel(struct bladerf *dev, struct channelConfig *c);
struct bladerf *setBoard();
int configureStream();
void *stream_callback(struct bladerf *dev, struct bladerf_stream *stream,
                      struct bladerf_metadata *metadata, void *samples,
                      size_t num_samples, void *user_data);
struct bladerf_stream *configureStream(struct bladerf *dev, struct bladerf_stream *stream, struct bladerf_data *data);
void closeBoard(int signo);
}; // namespace bladerfDriver