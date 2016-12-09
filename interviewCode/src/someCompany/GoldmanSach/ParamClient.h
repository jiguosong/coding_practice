/*
 * Copyright 2016 Goldman Sachs. Proprietary and Confidential.
 *
 * For candidate evaluation purposes only.  Please do not forward or copy.
 */

#ifndef PARAM_CLIENT_H
#define PARAM_CLIENT_H

#include <string>
#include <vector>

namespace Gs { namespace Amm {

struct GroupData;
struct SectorData;
struct SymbolData;

/**
 * The ParamListener class provides an interface for receiving ParamData updates via callbacks.
 */

class ParamListener
{
public:

    /**
     * Callback method that will be called automatically by ParamClient when a symbol level parameter update occurs.
     *
     * @param data Reference to SymbolData object with details of symbol level risk parameters and group/sector assignments.
     */
     
    virtual void onParam( const SymbolData & data ) = 0;

    /**
     * Callback method that will be called automatically by ParamClient when a group level parameter update occurs.
     *
     * @param data Reference to GroupData object with details of group level risk parameters.
     */

    virtual void onParam( const GroupData  & data ) = 0;

    /**
     * Callback method that will be called automatically by ParamClient when a sector level parameter update occurs.
     *
     * @param data Reference to SectorData object with details of sector level risk parameters.
     */
    virtual void onParam( const SectorData & data ) = 0;
};

class ParamClient
{
public:

    /**
     * Constructor subscribes the listener to parmeter updates.
     *
     * @param listener ParamListener object to receive parameter callbacks on.
     */

    ParamClient( ParamListener & listener );

    /// @cond
    // IGNORE: this is part of the test harness.
    void onParam( const GroupData  & data ) { m_listener.onParam( data ); }
    void onParam( const SectorData & data ) { m_listener.onParam( data ); }
    void onParam( const SymbolData & data ) { m_listener.onParam( data ); }

private:

    // IGNORE: this is part of the test harness.
    ParamListener & m_listener;

public:

    // IGNORE: this is part of the test harness.
    static std::vector< ParamClient * > s_paramClients;
    /// @endcond
};


} // Amm
} // Gs

#endif
