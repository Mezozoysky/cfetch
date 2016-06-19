//  cfetch - Copyright (C) 2016 Stanislav Demyanovich <mezozoysky@gmail.com>
//
//  This software is provided 'as-is', without any express or
//  implied warranty. In no event will the authors be held
//  liable for any damages arising from the use of this software.
//
//  Permission is granted to anyone to use this software for any purpose,
//  including commercial applications, and to alter it and redistribute
//  it freely, subject to the following restrictions:
//
//  1.  The origin of this software must not be misrepresented;
//      you must not claim that you wrote the original software.
//      If you use this software in a product, an acknowledgment
//      in the product documentation would be appreciated but
//      is not required.
//
//  2.  Altered source versions must be plainly marked as such,
//      and must not be misrepresented as being the original software.
//
//  3.  This notice may not be removed or altered from any
//      source distribution.

#include "Application.hpp"
#include <Poco/Util/HelpFormatter.h>
#include <iostream>
#include <sstream>

namespace cf
{

Application::Application()
: Poco::Util::Application()
, mIsHelpOptionRequested{ true }
{

}

Application::~Application()
{
}

void Application::initialize ( Poco::Util::Application& self )
{
    Poco::Util::Application::initialize ( self );
	//TODO: specific initialize stuff
}

void Application::uninitialize()
{
	//TODO: specific uninitialize stuff
    Poco::Util::Application::uninitialize();
}

void Application::defineOptions ( Poco::Util::OptionSet& options )
{
    Poco::Util::Application::defineOptions ( options );

	options.addOption(
		Poco::Util::Option( "help", "h", "print the help screen" )
		.required( false )
		.repeatable( false )
		.callback( Poco::Util::OptionCallback< Application >( this, 
&Application::helpOptionCallback ) )
	);
}

int Application::main ( const std::vector< std::string >& args )
{
	int exitCode{ EXIT_OK };
	
	if ( mIsHelpOptionRequested )
	{
		return ( exitCode );
	}
	
	std::ostringstream ss{ "Agrs:" };
	for ( auto arg: args )
	{
		ss << " " << arg;
	}
	
	std::cout << ss.str() << std::endl;
	
	return ( exitCode );
}

void Application::helpOptionCallback ( const std::string& name, const std::string& value )
{
	mIsHelpOptionRequested = true;
	Poco::Util::HelpFormatter hf( options() );
	hf.setCommand( commandName() );
	hf.setUsage( "[OPTIONS]" );
	hf.setHeader( "** help screen header **" );
	hf.setFooter( "** help screen footer **" );
	hf.setWidth( 80 );
	hf.format( std::cout );
	stopOptionsProcessing();
}


} // namespace cf