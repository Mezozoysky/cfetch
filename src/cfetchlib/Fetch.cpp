//  cfetch
//
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

#include <cfetchlib/Fetch.hpp>

#include <Poco/URI.h>
#include <Poco/URIStreamOpener.h>
#include <Poco/Net/HTTPStreamFactory.h>
#include <Poco/Net/FTPStreamFactory.h>
#include <Poco/StreamCopier.h>
#include <Poco/Path.h>
#include <memory>
#include <iostream>
#include <fstream>

namespace cfl
{
namespace fetch
{

// using namespace Poco;

void downloadFile( const Poco::URI& from, const Poco::Path& to ) noexcept
{
	Poco::Net::HTTPStreamFactory::registerFactory();
	Poco::Net::FTPStreamFactory::registerFactory();
	Poco::URIStreamOpener& opener{ Poco::URIStreamOpener::defaultOpener() };

	std::unique_ptr<std::istream> istr{ opener.open( from /*"file:///usr/include/stdio.h"*/ ) };
	std::cout << "path: " << to.toString() << std::endl;
	std::ofstream ostr{ to.toString() };
	Poco::StreamCopier::copyStream( *( istr.get() ), ostr );
}

} // namespace fetch
} // namespace cfl
