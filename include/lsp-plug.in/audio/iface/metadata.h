/*
 * Copyright (C) 2026 Linux Studio Plugins Project <https://lsp-plug.in/>
 *           (C) 2026 Vladimir Sadovnikov <sadko4u@gmail.com>
 *
 * This file is part of lsp-audio-iface
 * Created on: 6 апр. 2026 г.
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

#ifndef LSP_PLUG_IN_AUDIO_IFACE_METADATA_H_
#define LSP_PLUG_IN_AUDIO_IFACE_METADATA_H_

#include <lsp-plug.in/audio/iface/version.h>

namespace lsp
{
    namespace audio
    {
        /**
         * Audio backend metadata
         */
        typedef struct backend_metadata_t
        {
            const char         *id;             // Enumeration unique identifier
            const char         *display;        // Display name
            const char         *lc_key;         // Localized display name key
        } backend_metadata_t;

    } /* namespace audio */
} /* namespace lsp */



#endif /* LSP_PLUG_IN_AUDIO_IFACE_METADATA_H_ */
