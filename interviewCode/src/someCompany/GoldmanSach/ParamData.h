/*
 * Copyright 2016 Goldman Sachs. Proprietary and Confidential.
 *
 * For candidate evaluation purposes only.  Please do not forward or copy.
 */

#ifndef PARAM_DATA_H
#define PARAM_DATA_H

#include <string>

namespace Gs { namespace Amm {

struct ParamData
{
public:
    enum Type { INSERT, DELETE } m_type;

    ParamData( Type type ) : m_type( type ) {}

    bool isInsert() const { return m_type == INSERT; }
    bool isDelete() const { return m_type == DELETE; }
};

struct SymbolData : public ParamData
{
public:
    SymbolData( Type type,
                const char * symbol,
                const char * parentSectorId,
                const char * parentGroupId,
                unsigned int quantityThreshold,
                unsigned int quantityInterval,
                double       deltaThreshold,
                unsigned int deltaInterval )
            : ParamData( type ),
              m_symbol( symbol ), m_parentSectorId( parentSectorId ), m_parentGroupId( parentGroupId ),
              m_quantityThreshold( quantityThreshold ), m_quantityInterval( quantityInterval ),
              m_deltaThreshold( deltaThreshold ), m_deltaInterval( deltaInterval ) {}

    std::string  m_symbol;
    std::string  m_parentSectorId;
    std::string  m_parentGroupId;
    unsigned int m_quantityThreshold;
    unsigned int m_quantityInterval;
    double       m_deltaThreshold;
    unsigned int m_deltaInterval;
};

struct GroupData : public ParamData
{
public:
    GroupData(  Type type,
                const char * groupId,
                unsigned int quantityThreshold,
                unsigned int quantityInterval,
                double       deltaThreshold,
                unsigned int deltaInterval )
            : ParamData( type ),
              m_groupId( groupId ),
              m_quantityThreshold( quantityThreshold ), m_quantityInterval( quantityInterval ),
              m_deltaThreshold( deltaThreshold ), m_deltaInterval( deltaInterval ) {}
    
    std::string  m_groupId;
    unsigned int m_quantityThreshold;
    unsigned int m_quantityInterval;
    double       m_deltaThreshold;
    unsigned int m_deltaInterval;
};

struct SectorData : public ParamData
{
public:
    SectorData( Type type,
                const char * sectorId,
                unsigned int quantityThreshold,
                unsigned int quantityInterval,
                double       deltaThreshold,
                unsigned int deltaInterval )
            : ParamData( type ),
              m_sectorId( sectorId ),
              m_quantityThreshold( quantityThreshold ), m_quantityInterval( quantityInterval ),
              m_deltaThreshold( deltaThreshold ), m_deltaInterval( deltaInterval ) {}
    
    std::string  m_sectorId;
    unsigned int m_quantityThreshold;
    unsigned int m_quantityInterval;
    double       m_deltaThreshold;
    unsigned int m_deltaInterval;
};

} // Amm
} // Gs

#endif
