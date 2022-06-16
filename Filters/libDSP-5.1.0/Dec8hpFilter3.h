/*

    Decimation filter for rate 8
    Copyright (C) 2001 Jussi Laako

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


static const long lDec8hpFilterLen = 143l;

static const float fDec8hpFilterGain = 1.0f;
static const float fpDec8hpFilterCoeffs[] = {
    1.51537214817115E-6,
    -3.38566548797261E-6,
    6.1260133693259E-6,
    -9.61697370238982E-6,
    1.34932478232328E-5,
    -1.70987434844602E-5,
    1.94759376422661E-5,
    -1.94032165762811E-5,
    1.54904318908597E-5,
    -6.33697804582827E-6,
    -9.25146812357489E-6,
    3.20011636471709E-5,
    -6.18874365590239E-5,
    9.78643428359976E-5,
    -0.000137647878603663,
    0.000177597521918838,
    -0.000212739597345417,
    0.000236968717993799,
    -0.000243450003381578,
    0.000225225266100532,
    -0.000176002089040096,
    9.10776736583014E-5,
    3.16777652741889E-5,
    -0.00019087724048401,
    0.000380829442162886,
    -0.000591031540453392,
    0.000806061544217373,
    -0.00100597025209816,
    0.00116723903287699,
    -0.001264322400808,
    0.00127173643320193,
    -0.0011665899353587,
    0.000931390658942344,
    -0.000556900498905113,
    4.47684234742586E-5,
    0.000590355457311204,
    -0.00131952131998609,
    0.00209926427254315,
    -0.00287268085445224,
    0.0035719184337777,
    -0.00412208710529129,
    0.00444647598873342,
    -0.00447282189728101,
    0.00414024997705817,
    -0.00340639566367621,
    0.00225413734528869,
    -0.000697330067499386,
    -0.00121505967469343,
    0.00339695541505045,
    -0.00572573066638972,
    0.008045586962866,
    -0.0101738094483535,
    0.0119097357321021,
    -0.01304604364826,
    0.0133817461944534,
    -0.0127360966191059,
    0.0109624712432842,
    -0.00796122684757915,
    0.0036905333796953,
    0.00182573440972701,
    -0.00849380325577897,
    0.0161500350648934,
    -0.0245654372372798,
    0.0334545858706114,
    -0.0424885759847799,
    0.051311307001711,
    -0.0595581468493285,
    0.0668758164687398,
    -0.0729422158445592,
    0.0774848844136778,
    -0.0802968570045461,
    0.0812488377014015,
    -0.0802968570045461,
    0.0774848844136778,
    -0.0729422158445592,
    0.0668758164687398,
    -0.0595581468493285,
    0.051311307001711,
    -0.0424885759847799,
    0.0334545858706114,
    -0.0245654372372798,
    0.0161500350648934,
    -0.00849380325577897,
    0.00182573440972701,
    0.0036905333796953,
    -0.00796122684757915,
    0.0109624712432842,
    -0.0127360966191059,
    0.0133817461944534,
    -0.01304604364826,
    0.0119097357321021,
    -0.0101738094483535,
    0.008045586962866,
    -0.00572573066638972,
    0.00339695541505045,
    -0.00121505967469343,
    -0.000697330067499386,
    0.00225413734528869,
    -0.00340639566367621,
    0.00414024997705817,
    -0.00447282189728101,
    0.00444647598873342,
    -0.00412208710529129,
    0.0035719184337777,
    -0.00287268085445224,
    0.00209926427254315,
    -0.00131952131998609,
    0.000590355457311204,
    4.47684234742586E-5,
    -0.000556900498905113,
    0.000931390658942344,
    -0.0011665899353587,
    0.00127173643320193,
    -0.001264322400808,
    0.00116723903287699,
    -0.00100597025209816,
    0.000806061544217373,
    -0.000591031540453392,
    0.000380829442162886,
    -0.00019087724048401,
    3.16777652741889E-5,
    9.10776736583014E-5,
    -0.000176002089040096,
    0.000225225266100532,
    -0.000243450003381578,
    0.000236968717993799,
    -0.000212739597345417,
    0.000177597521918838,
    -0.000137647878603663,
    9.78643428359976E-5,
    -6.18874365590239E-5,
    3.20011636471709E-5,
    -9.25146812357489E-6,
    -6.33697804582827E-6,
    1.54904318908597E-5,
    -1.94032165762811E-5,
    1.94759376422661E-5,
    -1.70987434844602E-5,
    1.34932478232328E-5,
    -9.61697370238982E-6,
    6.1260133693259E-6,
    -3.38566548797261E-6,
    1.51537214817115E-6
};


static const double dDec8hpFilterGain = 1.0;
static const double dpDec8hpFilterCoeffs[] = {
    1.51537214817115E-6,
    -3.38566548797261E-6,
    6.1260133693259E-6,
    -9.61697370238982E-6,
    1.34932478232328E-5,
    -1.70987434844602E-5,
    1.94759376422661E-5,
    -1.94032165762811E-5,
    1.54904318908597E-5,
    -6.33697804582827E-6,
    -9.25146812357489E-6,
    3.20011636471709E-5,
    -6.18874365590239E-5,
    9.78643428359976E-5,
    -0.000137647878603663,
    0.000177597521918838,
    -0.000212739597345417,
    0.000236968717993799,
    -0.000243450003381578,
    0.000225225266100532,
    -0.000176002089040096,
    9.10776736583014E-5,
    3.16777652741889E-5,
    -0.00019087724048401,
    0.000380829442162886,
    -0.000591031540453392,
    0.000806061544217373,
    -0.00100597025209816,
    0.00116723903287699,
    -0.001264322400808,
    0.00127173643320193,
    -0.0011665899353587,
    0.000931390658942344,
    -0.000556900498905113,
    4.47684234742586E-5,
    0.000590355457311204,
    -0.00131952131998609,
    0.00209926427254315,
    -0.00287268085445224,
    0.0035719184337777,
    -0.00412208710529129,
    0.00444647598873342,
    -0.00447282189728101,
    0.00414024997705817,
    -0.00340639566367621,
    0.00225413734528869,
    -0.000697330067499386,
    -0.00121505967469343,
    0.00339695541505045,
    -0.00572573066638972,
    0.008045586962866,
    -0.0101738094483535,
    0.0119097357321021,
    -0.01304604364826,
    0.0133817461944534,
    -0.0127360966191059,
    0.0109624712432842,
    -0.00796122684757915,
    0.0036905333796953,
    0.00182573440972701,
    -0.00849380325577897,
    0.0161500350648934,
    -0.0245654372372798,
    0.0334545858706114,
    -0.0424885759847799,
    0.051311307001711,
    -0.0595581468493285,
    0.0668758164687398,
    -0.0729422158445592,
    0.0774848844136778,
    -0.0802968570045461,
    0.0812488377014015,
    -0.0802968570045461,
    0.0774848844136778,
    -0.0729422158445592,
    0.0668758164687398,
    -0.0595581468493285,
    0.051311307001711,
    -0.0424885759847799,
    0.0334545858706114,
    -0.0245654372372798,
    0.0161500350648934,
    -0.00849380325577897,
    0.00182573440972701,
    0.0036905333796953,
    -0.00796122684757915,
    0.0109624712432842,
    -0.0127360966191059,
    0.0133817461944534,
    -0.01304604364826,
    0.0119097357321021,
    -0.0101738094483535,
    0.008045586962866,
    -0.00572573066638972,
    0.00339695541505045,
    -0.00121505967469343,
    -0.000697330067499386,
    0.00225413734528869,
    -0.00340639566367621,
    0.00414024997705817,
    -0.00447282189728101,
    0.00444647598873342,
    -0.00412208710529129,
    0.0035719184337777,
    -0.00287268085445224,
    0.00209926427254315,
    -0.00131952131998609,
    0.000590355457311204,
    4.47684234742586E-5,
    -0.000556900498905113,
    0.000931390658942344,
    -0.0011665899353587,
    0.00127173643320193,
    -0.001264322400808,
    0.00116723903287699,
    -0.00100597025209816,
    0.000806061544217373,
    -0.000591031540453392,
    0.000380829442162886,
    -0.00019087724048401,
    3.16777652741889E-5,
    9.10776736583014E-5,
    -0.000176002089040096,
    0.000225225266100532,
    -0.000243450003381578,
    0.000236968717993799,
    -0.000212739597345417,
    0.000177597521918838,
    -0.000137647878603663,
    9.78643428359976E-5,
    -6.18874365590239E-5,
    3.20011636471709E-5,
    -9.25146812357489E-6,
    -6.33697804582827E-6,
    1.54904318908597E-5,
    -1.94032165762811E-5,
    1.94759376422661E-5,
    -1.70987434844602E-5,
    1.34932478232328E-5,
    -9.61697370238982E-6,
    6.1260133693259E-6,
    -3.38566548797261E-6,
    1.51537214817115E-6
};