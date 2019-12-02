#include "fuzzyset.h"

#include <algorithm>
#include <iterator>

namespace fuzzy
{
    FuzzySet::FuzzySet( const t_FZContainer& container, const std::string& name )
        : m_fzName( name )
    {
        if ( !isAcceptableMembership( container ) )
            throw "FuzzySet: not acceptable membership value.";

        std::copy_if( container.begin(), container.end(),
                      std::inserter( m_fzSet,  m_fzSet.end() ),
                      []( const auto& pair ) { return pair.second > 0; } );
    }

    FuzzySet& FuzzySet::operator=( const FuzzySet& fs )
    {
        this->m_fzName = fs.m_fzName;
        this->m_fzSet = fs.m_fzSet;
        return *this;
    }

    bool FuzzySet::isAcceptableMembership( const t_FZContainer& container ) const
    {
        return std::all_of( container.cbegin(),
                            container.cend(),
                            []( const auto& pair )
                            {
                                return pair.second >= 0 && pair.second <= 1;
                            } );
    }
} // namespace fuzzy