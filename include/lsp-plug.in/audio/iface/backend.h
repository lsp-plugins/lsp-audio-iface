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

#include <lsp-plug.in/common/types.h>
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
             * @param self ponter to backend_t structure
             * @param params connection parameters, NULL for default options.
             * @return status of operation
             */
            status_t    (* connect)(backend_t *self, const char *params);

            /**
             * Disconnect the audio backend
             * @param self ponter to backend_t structure
             * @return status of operation
             */
            status_t    (* disconnect)(backend_t *self);

            /**
             * Destroy backend and free memory allocated by the backend_t structure.
             * @param self ponter to backend_t structure
             */
            void        (* destroy)(backend_t *self);

        } backend_t;
    } /* namespace audio */
} /* namespace lsp */

#endif /* LSP_PLUG_IN_AUDIO_IFACE_BACKEND_H_ */
