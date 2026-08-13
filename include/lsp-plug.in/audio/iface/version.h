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

#ifndef LSP_PLUG_IN_AUDIO_IFACE_VERSION_H_
#define LSP_PLUG_IN_AUDIO_IFACE_VERSION_H_

#define LSP_AUDIO_IFACE_MAJOR           1
#define LSP_AUDIO_IFACE_MINOR           0
#define LSP_AUDIO_IFACE_MICRO           1

#if defined(LSP_AUDIO_IFACE_PUBLISHER)
    #define LSP_AUDIO_IFACE_PUBLIC          LSP_EXPORT_MODIFIER
#elif defined(LSP_AUDIO_IFACE_BUILTIN) || defined(LSP_IDE_DEBUG)
    #define LSP_AUDIO_IFACE_PUBLIC
#else
    #define LSP_AUDIO_IFACE_PUBLIC          LSP_IMPORT_MODIFIER
#endif

#define LSP_AUDIO_IFACE_VERSION_FUNC        lsp_audio_iface_version
#define LSP_AUDIO_IFACE_VERSION_FUNC_NAME   "lsp_audio_iface_version"

#define LSP_AUDIO_IFACE_DEF_VERSION_FUNC   \
    const ::lsp::version_t *LSP_AUDIO_IFACE_VERSION_FUNC() \
    { \
        static const ::lsp::version_t v=LSP_DEF_VERSION( \
            LSP_AUDIO_IFACE_MAJOR, \
            LSP_AUDIO_IFACE_MINOR, \
            LSP_AUDIO_IFACE_MICRO); \
        return &v; \
    }

#endif /* LSP_PLUG_IN_AUDIO_IFACE_VERSION_H_ */
