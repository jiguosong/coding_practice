/*
 * Copyright 2016 Goldman Sachs. Proprietary and Confidential.
 *
 * For candidate evaluation purposes only.  Please do not forward or copy.
 */

#include "ParamClient.h"

using namespace std;

namespace Gs { namespace Amm {

ParamClient::ParamClient( ParamListener & listener )
        : m_listener( listener )
{
    // IGNORE: this is part of the test harness.
    s_paramClients.push_back( this );
}

// IGNORE: this is part of the test harness.
std::vector< ParamClient * > ParamClient::s_paramClients;

} // Amm
} // Gs
