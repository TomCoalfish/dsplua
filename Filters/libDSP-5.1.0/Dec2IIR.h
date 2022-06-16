/*

    IIR Decimation filter for rate 2
    Copyright (C) 2002 Jussi Laako

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


#ifdef _MSC_VER
#pragma warning(disable:4305)
#endif


/* f1: 0.225,  f2: 0.25, r: 0.5, a: 72, t: chebyshev */

/*static const long lDec2IIRSize = 9l;

static const float fpDec2IIRCoeffs[][5] = {
{  // 0
    0.418751194466871,
    0.837502388933742,
    0.418751194466871,
    0.308156949354977,
    -0.983161727222462
},
{  // 1
    0.397205135297347,
    0.794410270594695,
    0.397205135297347,
    0.360761102685036,
    -0.949581643874426
},
{  // 2
    0.361407773475962,
    0.722815546951924,
    0.361407773475962,
    0.469402000490553,
    -0.9150330943944
},
{  // 3
    0.311666796583605,
    0.62333359316721,
    0.311666796583605,
    0.631918908006357,
    -0.878586094340777
},
{  // 4
    0.249374009142474,
    0.498748018284947,
    0.249374009142474,
    0.842562730317949,
    -0.840058766887844
},
{  // 5
    0.178376465580866,
    0.356752931161731,
    0.178376465580866,
    1.08705113135422,
    -0.800556993677684
},
{  // 6
    0.106488351221616,
    0.212976702443233,
    0.106488351221616,
    1.33713574639379,
    -0.763089151280256
},
{  // 7
    0.0459227831787746,
    0.0918455663575492,
    0.0459227831787746,
    1.54902955695302,
    -0.732720689668122
},
{  // 8
    0.0107148447358409,
    0.0214296894716819,
    0.0107148447358409,
    1.67256241302341,
    -0.715421791966771
}
};


static const double dpDec2IIRCoeffs[][5] = {
{  // 0
    0.418751194466871,
    0.837502388933742,
    0.418751194466871,
    0.308156949354977,
    -0.983161727222462
},
{  // 1
    0.397205135297347,
    0.794410270594695,
    0.397205135297347,
    0.360761102685036,
    -0.949581643874426
},
{  // 2
    0.361407773475962,
    0.722815546951924,
    0.361407773475962,
    0.469402000490553,
    -0.9150330943944
},
{  // 3
    0.311666796583605,
    0.62333359316721,
    0.311666796583605,
    0.631918908006357,
    -0.878586094340777
},
{  // 4
    0.249374009142474,
    0.498748018284947,
    0.249374009142474,
    0.842562730317949,
    -0.840058766887844
},
{  // 5
    0.178376465580866,
    0.356752931161731,
    0.178376465580866,
    1.08705113135422,
    -0.800556993677684
},
{  // 6
    0.106488351221616,
    0.212976702443233,
    0.106488351221616,
    1.33713574639379,
    -0.763089151280256
},
{  // 7
    0.0459227831787746,
    0.0918455663575492,
    0.0459227831787746,
    1.54902955695302,
    -0.732720689668122
},
{  // 8
    0.0107148447358409,
    0.0214296894716819,
    0.0107148447358409,
    1.67256241302341,
    -0.715421791966771
}
};*/


/* f1: 0.2375,  f2: 0.25, r: 0.5, a: 72, , t: chebyshev */

static const long lDec2IIRSize = 13l;

static const float fpDec2IIRCoeffs[][5] = {
{ // 0
    0.459004418051451,
    0.918008836102903,
    0.459004418051451,
    0.155134262260857,
    -0.991151934466663
},
{ // 1
    0.447178575196792,
    0.894357150393585,
    0.447178575196792,
    0.184734673655,
    -0.973448974442169
},
{ // 2
    0.427558698843714,
    0.855117397687427,
    0.427558698843714,
    0.245120931950537,
    -0.955355727325391
},
{ // 3
    0.399985971499631,
    0.799971942999262,
    0.399985971499631,
    0.336516277772076,
    -0.9364601637706
},
{ // 4
    0.364331495085477,
    0.728662990170954,
    0.364331495085477,
    0.459103677861684,
    -0.916429658203593
},
{ // 5
    0.320699673867401,
    0.641399347734802,
    0.320699673867401,
    0.612269340742105,
    -0.895068036211709
},
{ // 6
    0.269740071675564,
    0.539480143351128,
    0.269740071675564,
    0.79345075526482,
    -0.872411041967075
},
{ // 7
    0.213074368052099,
    0.426148736104198,
    0.213074368052099,
    0.996565165969699,
    -0.848862638178095
},
{ // 8
    0.153774550597037,
    0.307549101194074,
    0.153774550597037,
    1.21025217438177,
    -0.825350376769922
},
{ // 9
    0.0966903045296797,
    0.193380609059359,
    0.0966903045296797,
    1.4166699366456,
    -0.803431154764316
},
{ // 10
    0.0482616977037701,
    0.0965233954075403,
    0.0482616977037701,
    1.59217701574298,
    -0.785223806558058
},
{ // 11
    0.0154470799727272,
    0.0308941599454544,
    0.0154470799727272,
    1.71125459857363,
    -0.773042918464539
},
{ // 12
    0.0616098381078833,
    0.0616098381078833,
    0,
    0.876780323784233,
    0
}
};


static const double dpDec2IIRCoeffs[][5] = {
{ // 0
    0.459004418051451,
    0.918008836102903,
    0.459004418051451,
    0.155134262260857,
    -0.991151934466663
},
{ // 1
    0.447178575196792,
    0.894357150393585,
    0.447178575196792,
    0.184734673655,
    -0.973448974442169
},
{ // 2
    0.427558698843714,
    0.855117397687427,
    0.427558698843714,
    0.245120931950537,
    -0.955355727325391
},
{ // 3
    0.399985971499631,
    0.799971942999262,
    0.399985971499631,
    0.336516277772076,
    -0.9364601637706
},
{ // 4
    0.364331495085477,
    0.728662990170954,
    0.364331495085477,
    0.459103677861684,
    -0.916429658203593
},
{ // 5
    0.320699673867401,
    0.641399347734802,
    0.320699673867401,
    0.612269340742105,
    -0.895068036211709
},
{ // 6
    0.269740071675564,
    0.539480143351128,
    0.269740071675564,
    0.79345075526482,
    -0.872411041967075
},
{ // 7
    0.213074368052099,
    0.426148736104198,
    0.213074368052099,
    0.996565165969699,
    -0.848862638178095
},
{ // 8
    0.153774550597037,
    0.307549101194074,
    0.153774550597037,
    1.21025217438177,
    -0.825350376769922
},
{ // 9
    0.0966903045296797,
    0.193380609059359,
    0.0966903045296797,
    1.4166699366456,
    -0.803431154764316
},
{ // 10
    0.0482616977037701,
    0.0965233954075403,
    0.0482616977037701,
    1.59217701574298,
    -0.785223806558058
},
{ // 11
    0.0154470799727272,
    0.0308941599454544,
    0.0154470799727272,
    1.71125459857363,
    -0.773042918464539
},
{ // 12
    0.0616098381078833,
    0.0616098381078833,
    0,
    0.876780323784233,
    0
}
};
