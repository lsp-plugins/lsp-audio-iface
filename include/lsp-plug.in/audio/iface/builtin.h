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

#ifndef LSP_PLUG_IN_AUDIO_IFACE_BUILTIN_H_
#define LSP_PLUG_IN_AUDIO_IFACE_BUILTIN_H_

#include <lsp-plug.in/audio/iface/version.h>

#include <lsp-plug.in/common/types.h>
#include <lsp-plug.in/audio/iface/factory.h>

namespace lsp
{
    namespace audio
    {
        /**
         * This class allows to automatically register built-in factory
         */
        class LSP_HIDDEN_MODIFIER Factory
        {
            private:
                static Factory *pList;

                factory_t      *pFactory;
                Factory        *pNext;

            public:
                explicit Factory(factory_t *factory);
                Factory(const Factory &) = delete;
                Factory(Factory &&) = delete;
                ~Factory();

                Factory & operator = (const Factory &) = delete;
                Factory & operator = (Factory &&) = delete;

            public:
                inline const Factory           *next() const    { return pNext;  }

            public:
                static const Factory           *list()          { return pList;  }
                static factory_t               *enumerate(int index);
        };

        /**
         * Macro for simplifying definition of factory export
         */
        #define LSP_AUDIO_BUILTIN_FACTORY(symbol, factory)   \
            static ::lsp::audio::Factory symbol(factory);

        /**
         * The implementation of factory function that uses builtin factory
         * descriptor to enumerate all possible factories
         */
        #define LSP_AUDIO_BULTIN_FACTORY_FUNCTION \
            LSP_AUDIO_FACTORY_FUNCTION_HEADER(index) \
            { \
                return Factory::enumerate(index); \
            }

    } /* namespace audio */
} /* namespace lsp */

#endif /* LSP_PLUG_IN_AUDIO_IFACE_BUILTIN_H_ */

