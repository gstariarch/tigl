/* 
* Copyright (C) 2007-2013 German Aerospace Center (DLR/SC)
*
* Created: 2010-08-13 Markus Litz <Markus.Litz@dlr.de>
* Changed: $Id$ 
*
* Version: $Revision$
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
/**
* @file
* @brief  Export routines for CPACS configurations.
*/

#ifndef CTIGLEXPORTIGES_H
#define CTIGLEXPORTIGES_H

#include "tigl_config.h"
#include "tigl_internal.h"
#include "PNamedShape.h"
#include "ListPNamedShape.h"
#include "CCPACSImportExport.h"

class IGESControl_Writer;

namespace tigl 
{

class CCPACSConfiguration;

class CTiglExportIges
{

public:
    // Constructor
    TIGL_EXPORT CTiglExportIges();

    // Virtual Destructor
    TIGL_EXPORT virtual ~CTiglExportIges(void);

    //  Adds the whole configuration fused, to the step file
    TIGL_EXPORT void AddConfiguration(CCPACSConfiguration& config);

    //  Adds the configuration, boolean fused, to the step file
    TIGL_EXPORT void AddFusedConfiguration(CCPACSConfiguration& config);

    // Adds a shape to the step file
    TIGL_EXPORT void AddShape(PNamedShape shape);

    // Sets the type of storing shapes to iges
    TIGL_EXPORT void SetGroupMode(ShapeGroupMode mode);

    // Writes the IGES file
    TIGL_EXPORT bool Write(const std::string& filename) const;

protected:

private:
    // Assignment operator
    void operator=(const CTiglExportIges& ) { /* Do nothing */ }
    void AddToIges(PNamedShape shape, IGESControl_Writer& writer, int level = 0) const;

    ShapeGroupMode  _groupMode;    /**< Type specifying how to group faces in the iges file */
    ListPNamedShape _shapes;
    void SetTranslationParameters() const;
};

} // end namespace tigl

#endif // CTIGLEXPORTIGES_H
