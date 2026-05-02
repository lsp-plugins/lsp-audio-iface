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
             * Set overall latency for the backend.
             * @param self pointer to backend_t structure
             * @param latency port latency in samples
             * @return status of operation
             */
            status_t        (* set_latency)(backend_t *self, uint32_t latency);

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
             * Register data port.
             * @param self ponter to backend_t structure
             * @param id unique string port identifier
             * @param flags port flags @see audio::port_flags_t
             * @return unique port identifier or negative error code.
             */
            port_id_t       (* register_port)(backend_t *self, const char *id, uint32_t flags);

            /**
             * Unregister data port.
             * @param self pointer to backend_t structure
             * @param port audio port instance
             */
            status_t        (* unregister_port)(backend_t *self, port_id_t port_id);

            /**
             * Get system name of the port
             * @param self pointer to backend_t structure
             * @param port_id port identifier
             * @return system name of the port or NULL
             */
            const char     *(* port_system_name)(audio::backend_t *self, port_id_t port_id);

            /**
             * Estimate connection between two ports.
             *
             * @param self pointer to backend_t structure
             * @param source the name of the source output port
             * @param destination the name of the destination input port
             * @return status of operation, STATUS_ALREADY_BOUND if already connected.
             */
            status_t        (* connect_ports)(backend_t *self, const char *source, const char *destination);

            /**
             * Break connection between two ports.
             *
             * @param self pointer to backend_t structure
             * @param source the name of the source output port
             * @param destination the name of the destination input port
             * @return status of operation, STATUS_ALREADY_BOUND if already connected.
             */
            status_t        (* disconnect_ports)(backend_t *self, const char *source, const char *destination);

            /**
             * Get number of audio buffers for the port. Input audio buffers may contain more than one
             * buffers that should be mixed together.
             * @note This method may be called only inside of the on_process() callback.
             *
             * @param self pointer to backend_t structure
             * @param port_id unique port identifier
             */
            size_t          (* audio_buffers_count)(backend_t *self, port_id_t port_id);

            /**
             * Get raw audio buffer associated with the port.
             * @note This method may be called only inside of the on_process() callback.
             * This method can return NULL if buffer is empty (filled with zeros) or not
             * present. NULL can only be returned if audio_buffers_count returns value of
             * less than two.
             *
             * @param self pointer to backend_t structure
             * @param port_id unique port identifier
             * @param index buffer index
             * @return pointer to data or NULL if buffer is empty or not present
             */
            float          *(* get_audio_buffer)(backend_t *self, port_id_t port_id, size_t index);

            /**
             * Get number of MIDI events for the MIDI port.
             * @note This method may be called only inside of the on_process() callback.
             *
             * @param self pointer to backend_t structure
             * @param port_id unique port identifier
             */
            size_t          (* midi_events_count)(backend_t *self, port_id_t port_id);

            /**
             * Get MIDI event from input MIDI port. Retreived MIDI events are sorted chronologically.
             * @note This method may be called only inside of the on_process() callback.
             *
             * @param self pointer to backend_t structure
             * @param port_id unique port identifier
             * @param event the pointer to store MIDI event data
             * @param index index of the requested MIDI event
             * @return status of operation, STATUS_NO_DATA if there is no such MIDI event
             */
            status_t        (* read_midi_event)(backend_t *self, port_id_t port_id, midi_event_t *event, uint32_t index);

            /**
             * Submit new MIDI event to output MIDI port. Submitted MIDI events SHOULD be sorted chronologically.
             * @note This method may be called only inside of the on_process() callback.
             *
             * @param self pointer to backend_t structure
             * @param port_id unique port identifier
             * @param timestamp MIDI event timestamp
             * @param size size of the MIDI event
             * @return pointer to the memory for serializing the MIDI event or NULL on error
             */
            uint8_t        *(* write_midi_event)(backend_t *self, port_id_t port_id, uint32_t timestamp, uint32_t size);

        } backend_t;
    } /* namespace audio */
} /* namespace lsp */

#endif /* LSP_PLUG_IN_AUDIO_IFACE_BACKEND_H_ */
