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

#ifndef CFETCHLIB_FETCH_HPP
#define CFETCHLIB_FETCH_HPP

#include <cfetchlib/Config.hpp>

namespace Poco
{
	class URI;
	class Path;
}

namespace cfl
{
namespace fetch
{

	void downloadFile( const Poco::URI& from, const Poco::Path& to ) noexcept;

} // namespace fetch
} // namespace cfl

#endif /* end of include guard: CFETCHLIB_FETCH_HPP */
