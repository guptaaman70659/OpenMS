// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//
// --------------------------------------------------------------------------
//                   OpenMS Mass Spectrometry Framework
// --------------------------------------------------------------------------
//  Copyright (C) 2003-2006 -- Oliver Kohlbacher, Knut Reinert
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// --------------------------------------------------------------------------
// $Maintainer: Thomas Kadauke $
// --------------------------------------------------------------------------

#ifndef OPENMS_FORMAT_PEAKFILEOPTIONS_H
#define OPENMS_FORMAT_PEAKFILEOPTIONS_H

#include <OpenMS/DATASTRUCTURES/DRange.h>

namespace OpenMS
{
	/**
		@brief Options for loading files containing peak data.

		@ingroup FileIO
	*/
	class PeakFileOptions
	{
	public:
		///Default constructor
		PeakFileOptions();
		///Destructor
		~PeakFileOptions();

		void setMetadataOnly(bool only);
		bool getMetadataOnly() const;
		
		void setRTRange(const DRange<1>& range);
		bool hasRTRange();
		const DRange<1>& getRTRange() const;
		
		void setMZRange(const DRange<1>& range);
		bool hasMZRange();
		const DRange<1>& getMZRange() const;

	private:
		bool metadata_only_;
		bool has_rt_range_;
		bool has_mz_range_;
		DRange<1> rt_range_;
		DRange<1> mz_range_;
	};

} // namespace OpenMS

#endif // OPENMS_FORMAT_PEAKFILEOPTIONS_H
