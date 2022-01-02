/*
* play.hpp
* Author : Skalefou
* Creation date: 02/01/2022 (D/M/Y)
* Date of last update : 02/01/2022 (D/M/Y)
*
* This file describes the "Option" class
*/

#ifndef OPTION_HPP
#define OPTION_HPP
#pragma once

class Option
{
public:
	Option();
	void setCanOpenOption(const bool canOpenOption);
	bool canOpenOption() const;
	void setOption(const bool option);
	bool getOption() const;
	void run();

private:
	bool m_option, m_canOpenOption;
};

#endif