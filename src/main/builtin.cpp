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

#include <lsp-plug.in/audio/iface/builtin.h>

namespace lsp
{
    namespace audio
    {
        Factory *Factory::pList = NULL;

        Factory::Factory(factory_t *factory)
        {
            pFactory    = factory;
            pNext       = pList;

            pList       = this;
        }

        Factory::~Factory()
        {
            pFactory    = NULL;
            pNext       = NULL;

            if (pList == this)
                pList = NULL;
        }

        factory_t *Factory::enumerate(int index)
        {
            if (index < 0)
                return NULL;

            // Lookup the corresponding item in the list
            const Factory *ptr = pList;
            while ((index--) > 0)
            {
                if (ptr == NULL)
                    break;
                ptr     = ptr->next();
            }

            return (ptr != NULL) ? ptr->pFactory : NULL;
        }
    } /* namespace audio */
} /* namespace lsp */


