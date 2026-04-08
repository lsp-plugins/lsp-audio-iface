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

#ifndef LSP_PLUG_IN_AUDIO_IFACE_BACKEND_H_
#define LSP_PLUG_IN_AUDIO_IFACE_BACKEND_H_

#include <lsp-plug.in/audio/iface/version.h>

#include <lsp-plug.in/audio/iface/types.h>
#include <lsp-plug.in/common/status.h>

namespace lsp
{
    namespace audio
    {
        /**
         * Audio backend interface, just functions that should be called on a structure instance.
         */
        typedef struct backend_t
        {
            /**
             * Connect to the audio backend
             * @param self pointer to backend_t structure
             * @param params connection parameters, NULL for default options.
             * @param callbacks connection callbacks.
             * @param user_data user data passed to callbacks.
             * @return status of operation
             */
            status_t        (* connect)(
                backend_t *self,
                const connection_params_t *params,
                const callbacks_t *callbacks,
                void *user_data);

            /**
             * Disconnect the audio backend
             * @param self ponter to backend_t structure
             * @return status of operation
             */
            status_t        (* disconnect)(backend_t *self);

            /**
             * Destroy backend and free memory allocated by the backend_t structure.
             * @param self pointer to backend_t structure
             */
            void            (* destroy)(backend_t *self);

            /**
             * Create data port
             * @param self ponter to backend_t structure
             * @param id unique string port identifier
             * @param flags port flags @see audio::port_flags_t
             * @return unique port identifier or negative error code.
             */
            port_id_t       (* register_port)(backend_t *self, const char *id, uint32_t flags);

            /**
             * Destroy data port
             * @param self pointer to backend_t structure
             * @param port audio port instance
             */
            status_t        (* unregister_port)(backend_t *self, port_id_t port_id);

            /**
             * Set latency for the port
             * @param self pointer to backend_t structure
             * @param port_id unique port identifier
             * @param latency port latency in samples
             * @return status of operation
             */
            status_t        (* set_port_latency)(backend_t *self, port_id_t port_id, uint32_t latency);

            /**
             * Get number of audio buffers for the port. Input audio buffers may contain more than one
             * buffers that should be mixed together.
             * @param self pointer to backend_t structure
             * @param port_id unique port identifier
             */
            size_t          (* audio_buffer_count)(backend_t *self, port_id_t port_id);

            /**
             * Get raw audio buffer associated with the port
             * @param self pointer to backend_t structure
             * @param port_id unique port identifier
             * @param index buffer index
             * @return pointer to data or NULL if buffer is empty or not present
             */
            float          *(* get_audio_buffer)(backend_t *self, port_id_t port_id, size_t index);


        } backend_t;
    } /* namespace audio */
} /* namespace lsp */

#endif /* LSP_PLUG_IN_AUDIO_IFACE_BACKEND_H_ */
