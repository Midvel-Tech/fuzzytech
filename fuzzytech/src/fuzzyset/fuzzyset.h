#pragma once

#include <string>
#include <map>

namespace fuzzy
{
    using t_FZContainer = std::map<int, double>;

    class FuzzySet
    {
    public:
        explicit FuzzySet( const std::string& name = "newfset" )
            : m_fzName( name )
        {
        }

        explicit FuzzySet( const t_FZContainer& container, const std::string& name = "newfset" );

        FuzzySet( const FuzzySet& fs ) : m_fzName( fs.m_fzName ), m_fzSet( fs.m_fzSet )
        {
        }

        FuzzySet& operator=( const FuzzySet& fs );

        ~FuzzySet() = default;


        inline std::string const& name() const { return m_fzName; }

    protected:
        bool isAcceptableMembership( const t_FZContainer& container ) const;
    private:
        std::string m_fzName;
        t_FZContainer m_fzSet;

    }; // class FuzzySet

} // namespace fuzzy