#include "option.hpp"

Option::Option() : m_option(false), m_canOpenOption(true)
{

}

void Option::setCanOpenOption(const bool canOpenOption)
{
	m_canOpenOption = canOpenOption;
}

bool Option::canOpenOption() const
{
	return m_canOpenOption;
}

void Option::setOption(const bool option)
{
	m_option = option;
}

bool Option::getOption() const
{
	return m_option;
}

