/*

    Base class for FIR based multirate filters, header
    Copyright (C) 2000-2005 Jussi Laako

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*/


#include <dsp/DSPOp.hh>


#ifndef FIRMULTIRATE_HH
    #define FIRMULTIRATE_HH


    /**
        Base class for FIR based multirate filters.

        Data is is filtered using FIR filter by factor 2, 3, 4 or 8.
    */
    class clFIRMultiRate
    {
        protected:
            float fGain;  ///< Filter gain
            double dGain;  ///< Filter gain
            long lFactor;  ///< Rate change factor
            clDSPOp FIR;
        public:
            clFIRMultiRate ();
            virtual ~clFIRMultiRate ();
            /**
                Initialize filter, filtering factor must be 2, 3, 4 or 8.
                You can re-initialize without uninitializing first.

                The NULL pointer is used to select correct overloaded function
                matching input datatype.

                \param FactorP Rate change factor
                \param NullPtr NULL pointer
                \param HighPass High-pass filter?
            */
            bool Initialize (long, const float *, bool = false);
            /// \overload
            bool Initialize (long, const double *, bool = false);
            /**
                Uninitialize filter.
            */
            void Uninitialize ();
    };

#endif
