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

#ifndef LSP_PLUG_IN_AUDIO_IFACE_FACTORY_H_
#define LSP_PLUG_IN_AUDIO_IFACE_FACTORY_H_

#include <lsp-plug.in/audio/iface/version.h>

#include <lsp-plug.in/audio/iface/backend.h>
#include <lsp-plug.in/audio/iface/metadata.h>

#define LSP_AUDIO_FACTORY_FUNCTION                  lsp_audio_factory
#define LSP_AUDIO_FACTORY_FUNCTION_NAME             "lsp_audio_factory"
#define LSP_AUDIO_FACTORY_FUNCTION_HEADER(index)    ::lsp::audio::factory_t *LSP_AUDIO_FACTORY_FUNCTION(int index)

namespace lsp
{
    namespace audio
    {
        /**
         * Factory for obtaining 3D rendering backend metadata and
         * constructing 3D backend instance
         */
        typedef struct factory_t
        {
            /**
             * Get backend metadata
             * @param self pointer to factory_t structure
             * @param id backend identifier, starting with 0
             * @return status of operation or NULL if there is no such backend
             */
            const backend_metadata_t        *(* metadata)(factory_t *self, size_t id);

            /**
             * Create backend
             * @param self pointer to factory_t structure
             * @param id backend identifier
             * @return status of operation
             */
            backend_t                       *(* create)(factory_t *self, size_t id);

        } factory_t;

        /**
         * Factory function prototype
         * @param index the enumeration factory number starting with 0
         * @return pointer to the factory function or NULL if there are no more items in enumeration
         */
        typedef factory_t *(* factory_function_t)(int index);

    } /* namespace audio */
} /* namespace lsp */

#endif /* LSP_PLUG_IN_AUDIO_IFACE_FACTORY_H_ */
