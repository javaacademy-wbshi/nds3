#ifndef NDSINIFILEPARSERIMPL_H
#define NDSINIFILEPARSERIMPL_H

#include <map>
#include <string>

namespace nds
{

class IniFileParserImpl
{
public:
    IniFileParserImpl(std::istream& inputStream);

    /**
     * @brief Retrieve the value for a specific key in the parsed INI file.
     *
     * Throws
     * @param section
     * @param key
     * @param defaultValue
     * @return
     */
    const std::string& getString(const std::string& section, const std::string& key, const std::string& defaultValue) const;

    bool keyExists(const std::string& section, const std::string& key) const;

private:

    typedef std::pair<std::string, std::string> keyValue_t;

    static std::string trim(const std::string& string);

    static std::string getSection(const std::string& line);

    static size_t findFirstUnescapedChar(const std::string& string, const char findChar, const size_t startPosition = 0);

    static keyValue_t getKeyValue(const std::string& line);

    typedef std::map<std::string, std::string> keyValueMap_t;
    typedef std::map<std::string, keyValueMap_t> sectionKeyMap_t;

    sectionKeyMap_t m_sections;
};

}

#endif // NDSINIFILEPARSERIMPL_H
