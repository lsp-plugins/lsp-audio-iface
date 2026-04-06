/*
 * Copyright (C) 2026 Linux Studio Plugins Project <https://lsp-plug.in/>
 *           (C) 2026 Vladimir Sadovnikov <sadko4u@gmail.com>
 *
 * This file is part of lsp-audio-iface
 * Created on: 06 апр. 2026 г.
 *
 * lsp-audio-iface is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * lsp-audio-iface is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with lsp-audio-iface. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef LSP_PLUG_IN_AUDIO_IFACE_TYPES_H_
#define LSP_PLUG_IN_AUDIO_IFACE_TYPES_H_

#include <lsp-plug.in/audio/iface/version.h>

#include <lsp-plug.in/common/status.h>
#include <lsp-plug.in/common/types.h>

namespace lsp
{
    namespace audio
    {
        /**
         * Input/Output parameters
         */
        typedef struct io_parameters_t
        {
            /**
             * Current sample rate
             */
            size_t          sample_rate;

            /**
             * Current buffer size
             */
            size_t          buffer_size;

            /**
             * Maximum buffer size
             */
            size_t          max_buffer_size;
        } io_parameters_t;

        /**
         * Input/Output position state
         */
        typedef struct io_position_t
        {
            /**
             * Frame number
             */
            uint32_t        frame;

            /**
             * Current bar
             */
            int32_t         bar;

            /**
             * Current beat
             */
            int32_t         beat;

            /**
             * Current tick within the bar
             */
            int32_t         tick;

            /** The rate of the progress of time as a fraction of normal speed.
             * For example, a rate of 0.0 is stopped, 1.0 is rolling at normal
             * speed, 0.5 is rolling at half speed, -1.0 is reverse, and so on.
             */
            float           speed;

            /**
             * Time signature numerator (e.g. 3 for 3/4)
             */
            float           numerator;

            /**
             * Time signature denominator (e.g. 4 for 3/4)
             */
            float           denominator;

            /**
             * Current tempo in beats per minute
             */
            float           beats_per_minute;

            /**
             * The tempo increment/decrement on each additional sample
             */
            float           beats_per_minute_change;

            /**
             * Number of ticks per beat
             */
            double          ticks_per_beat;

        } io_position_t;

        /**
         * Backend connection parameters
         */
        typedef struct connection_params_t
        {
            /**
             * Optional connection URL
             */
            const char *url;

            /**
             * Optional client name
             */
            const char *client_name;

        } connection_params_t;

        /**
         * Backend connection callbacks
         */
        typedef struct callbacks_t
        {
            /**
             * Issued when connection to the audio system has been initiated
             * @param user_data user data
             * @param params current I/O parameters
             * @return status of operation
             */
            status_t        (* on_connected)(void *user_data, const io_parameters_t *params);

            /**
             * Issued when audio processing has been activated
             * @param user_data user data
             * @param params current I/O parameters
             * @return status of operation
             */
            status_t        (* on_activated)(void *user_data);

            /**
             * Issued when the I/O parameters have changed
             * @param user_data user data
             * @param params new I/O parameters
             * @return status of operation
             */
            status_t        (* on_io_changed)(void *user_data, const io_parameters_t *params);

            /**
             * Issued when the backend is required to perform audio processing
             * @param user_data user data
             * @param position current processing position
             * @return status of operation
             */
            status_t        (* on_process)(void *user_data, const io_position_t *position);

            /**
             * Issued when audio processing has been deactivated
             * @param user_data user data
             * @param params current I/O parameters
             * @return status of operation
             */
            status_t        (* on_deactivated)(void *user_data);

            /**
             * Issued when connection to the audio system has been lost
             * @param user_data user data
             */
            void            (* on_connection_lost)(void *user_data);

            /**
             * Issued when connection to the audio system has been closed
             * @param user_data user data
             */
            void            (* on_disconnected)(void *user_data);

        } callback_t;



    } /* namespace audio */
} /* namespace lsp */

#endif /* LSP_PLUG_IN_AUDIO_IFACE_TYPES_H_ */
