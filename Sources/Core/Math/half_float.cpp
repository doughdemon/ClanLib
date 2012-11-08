/*
**  ClanLib SDK
**  Copyright (c) 1997-2012 The ClanLib Team
**
**  This software is provided 'as-is', without any express or implied
**  warranty.  In no event will the authors be held liable for any damages
**  arising from the use of this software.
**
**  Permission is granted to anyone to use this software for any purpose,
**  including commercial applications, and to alter it and redistribute it
**  freely, subject to the following restrictions:
**
**  1. The origin of this software must not be misrepresented; you must not
**     claim that you wrote the original software. If you use this software
**     in a product, an acknowledgment in the product documentation would be
**     appreciated but is not required.
**  2. Altered source versions must be plainly marked as such, and must not be
**     misrepresented as being the original software.
**  3. This notice may not be removed or altered from any source distribution.
**
**  Note: Some of the libraries ClanLib may link to may have additional
**  requirements or restrictions.
**
**  File Author(s):
**
**    Jeroen van der Zijp (Based on the paper "Fast Half Float Conversions" by Jeroen van der Zijp)
*/

#include "Core/precomp.h"
#include "API/Core/Math/half_float.h"

namespace clan
{

unsigned int HalfFloat::mantissa_table[2048] =
{
	0,
	864026624,
	872415232,
	876609536,
	880803840,
	882900992,
	884998144,
	887095296,
	889192448,
	890241024,
	891289600,
	892338176,
	893386752,
	894435328,
	895483904,
	896532480,
	897581056,
	898105344,
	898629632,
	899153920,
	899678208,
	900202496,
	900726784,
	901251072,
	901775360,
	902299648,
	902823936,
	903348224,
	903872512,
	904396800,
	904921088,
	905445376,
	905969664,
	906231808,
	906493952,
	906756096,
	907018240,
	907280384,
	907542528,
	907804672,
	908066816,
	908328960,
	908591104,
	908853248,
	909115392,
	909377536,
	909639680,
	909901824,
	910163968,
	910426112,
	910688256,
	910950400,
	911212544,
	911474688,
	911736832,
	911998976,
	912261120,
	912523264,
	912785408,
	913047552,
	913309696,
	913571840,
	913833984,
	914096128,
	914358272,
	914489344,
	914620416,
	914751488,
	914882560,
	915013632,
	915144704,
	915275776,
	915406848,
	915537920,
	915668992,
	915800064,
	915931136,
	916062208,
	916193280,
	916324352,
	916455424,
	916586496,
	916717568,
	916848640,
	916979712,
	917110784,
	917241856,
	917372928,
	917504000,
	917635072,
	917766144,
	917897216,
	918028288,
	918159360,
	918290432,
	918421504,
	918552576,
	918683648,
	918814720,
	918945792,
	919076864,
	919207936,
	919339008,
	919470080,
	919601152,
	919732224,
	919863296,
	919994368,
	920125440,
	920256512,
	920387584,
	920518656,
	920649728,
	920780800,
	920911872,
	921042944,
	921174016,
	921305088,
	921436160,
	921567232,
	921698304,
	921829376,
	921960448,
	922091520,
	922222592,
	922353664,
	922484736,
	922615808,
	922746880,
	922812416,
	922877952,
	922943488,
	923009024,
	923074560,
	923140096,
	923205632,
	923271168,
	923336704,
	923402240,
	923467776,
	923533312,
	923598848,
	923664384,
	923729920,
	923795456,
	923860992,
	923926528,
	923992064,
	924057600,
	924123136,
	924188672,
	924254208,
	924319744,
	924385280,
	924450816,
	924516352,
	924581888,
	924647424,
	924712960,
	924778496,
	924844032,
	924909568,
	924975104,
	925040640,
	925106176,
	925171712,
	925237248,
	925302784,
	925368320,
	925433856,
	925499392,
	925564928,
	925630464,
	925696000,
	925761536,
	925827072,
	925892608,
	925958144,
	926023680,
	926089216,
	926154752,
	926220288,
	926285824,
	926351360,
	926416896,
	926482432,
	926547968,
	926613504,
	926679040,
	926744576,
	926810112,
	926875648,
	926941184,
	927006720,
	927072256,
	927137792,
	927203328,
	927268864,
	927334400,
	927399936,
	927465472,
	927531008,
	927596544,
	927662080,
	927727616,
	927793152,
	927858688,
	927924224,
	927989760,
	928055296,
	928120832,
	928186368,
	928251904,
	928317440,
	928382976,
	928448512,
	928514048,
	928579584,
	928645120,
	928710656,
	928776192,
	928841728,
	928907264,
	928972800,
	929038336,
	929103872,
	929169408,
	929234944,
	929300480,
	929366016,
	929431552,
	929497088,
	929562624,
	929628160,
	929693696,
	929759232,
	929824768,
	929890304,
	929955840,
	930021376,
	930086912,
	930152448,
	930217984,
	930283520,
	930349056,
	930414592,
	930480128,
	930545664,
	930611200,
	930676736,
	930742272,
	930807808,
	930873344,
	930938880,
	931004416,
	931069952,
	931135488,
	931168256,
	931201024,
	931233792,
	931266560,
	931299328,
	931332096,
	931364864,
	931397632,
	931430400,
	931463168,
	931495936,
	931528704,
	931561472,
	931594240,
	931627008,
	931659776,
	931692544,
	931725312,
	931758080,
	931790848,
	931823616,
	931856384,
	931889152,
	931921920,
	931954688,
	931987456,
	932020224,
	932052992,
	932085760,
	932118528,
	932151296,
	932184064,
	932216832,
	932249600,
	932282368,
	932315136,
	932347904,
	932380672,
	932413440,
	932446208,
	932478976,
	932511744,
	932544512,
	932577280,
	932610048,
	932642816,
	932675584,
	932708352,
	932741120,
	932773888,
	932806656,
	932839424,
	932872192,
	932904960,
	932937728,
	932970496,
	933003264,
	933036032,
	933068800,
	933101568,
	933134336,
	933167104,
	933199872,
	933232640,
	933265408,
	933298176,
	933330944,
	933363712,
	933396480,
	933429248,
	933462016,
	933494784,
	933527552,
	933560320,
	933593088,
	933625856,
	933658624,
	933691392,
	933724160,
	933756928,
	933789696,
	933822464,
	933855232,
	933888000,
	933920768,
	933953536,
	933986304,
	934019072,
	934051840,
	934084608,
	934117376,
	934150144,
	934182912,
	934215680,
	934248448,
	934281216,
	934313984,
	934346752,
	934379520,
	934412288,
	934445056,
	934477824,
	934510592,
	934543360,
	934576128,
	934608896,
	934641664,
	934674432,
	934707200,
	934739968,
	934772736,
	934805504,
	934838272,
	934871040,
	934903808,
	934936576,
	934969344,
	935002112,
	935034880,
	935067648,
	935100416,
	935133184,
	935165952,
	935198720,
	935231488,
	935264256,
	935297024,
	935329792,
	935362560,
	935395328,
	935428096,
	935460864,
	935493632,
	935526400,
	935559168,
	935591936,
	935624704,
	935657472,
	935690240,
	935723008,
	935755776,
	935788544,
	935821312,
	935854080,
	935886848,
	935919616,
	935952384,
	935985152,
	936017920,
	936050688,
	936083456,
	936116224,
	936148992,
	936181760,
	936214528,
	936247296,
	936280064,
	936312832,
	936345600,
	936378368,
	936411136,
	936443904,
	936476672,
	936509440,
	936542208,
	936574976,
	936607744,
	936640512,
	936673280,
	936706048,
	936738816,
	936771584,
	936804352,
	936837120,
	936869888,
	936902656,
	936935424,
	936968192,
	937000960,
	937033728,
	937066496,
	937099264,
	937132032,
	937164800,
	937197568,
	937230336,
	937263104,
	937295872,
	937328640,
	937361408,
	937394176,
	937426944,
	937459712,
	937492480,
	937525248,
	937558016,
	937590784,
	937623552,
	937656320,
	937689088,
	937721856,
	937754624,
	937787392,
	937820160,
	937852928,
	937885696,
	937918464,
	937951232,
	937984000,
	938016768,
	938049536,
	938082304,
	938115072,
	938147840,
	938180608,
	938213376,
	938246144,
	938278912,
	938311680,
	938344448,
	938377216,
	938409984,
	938442752,
	938475520,
	938508288,
	938541056,
	938573824,
	938606592,
	938639360,
	938672128,
	938704896,
	938737664,
	938770432,
	938803200,
	938835968,
	938868736,
	938901504,
	938934272,
	938967040,
	938999808,
	939032576,
	939065344,
	939098112,
	939130880,
	939163648,
	939196416,
	939229184,
	939261952,
	939294720,
	939327488,
	939360256,
	939393024,
	939425792,
	939458560,
	939491328,
	939524096,
	939540480,
	939556864,
	939573248,
	939589632,
	939606016,
	939622400,
	939638784,
	939655168,
	939671552,
	939687936,
	939704320,
	939720704,
	939737088,
	939753472,
	939769856,
	939786240,
	939802624,
	939819008,
	939835392,
	939851776,
	939868160,
	939884544,
	939900928,
	939917312,
	939933696,
	939950080,
	939966464,
	939982848,
	939999232,
	940015616,
	940032000,
	940048384,
	940064768,
	940081152,
	940097536,
	940113920,
	940130304,
	940146688,
	940163072,
	940179456,
	940195840,
	940212224,
	940228608,
	940244992,
	940261376,
	940277760,
	940294144,
	940310528,
	940326912,
	940343296,
	940359680,
	940376064,
	940392448,
	940408832,
	940425216,
	940441600,
	940457984,
	940474368,
	940490752,
	940507136,
	940523520,
	940539904,
	940556288,
	940572672,
	940589056,
	940605440,
	940621824,
	940638208,
	940654592,
	940670976,
	940687360,
	940703744,
	940720128,
	940736512,
	940752896,
	940769280,
	940785664,
	940802048,
	940818432,
	940834816,
	940851200,
	940867584,
	940883968,
	940900352,
	940916736,
	940933120,
	940949504,
	940965888,
	940982272,
	940998656,
	941015040,
	941031424,
	941047808,
	941064192,
	941080576,
	941096960,
	941113344,
	941129728,
	941146112,
	941162496,
	941178880,
	941195264,
	941211648,
	941228032,
	941244416,
	941260800,
	941277184,
	941293568,
	941309952,
	941326336,
	941342720,
	941359104,
	941375488,
	941391872,
	941408256,
	941424640,
	941441024,
	941457408,
	941473792,
	941490176,
	941506560,
	941522944,
	941539328,
	941555712,
	941572096,
	941588480,
	941604864,
	941621248,
	941637632,
	941654016,
	941670400,
	941686784,
	941703168,
	941719552,
	941735936,
	941752320,
	941768704,
	941785088,
	941801472,
	941817856,
	941834240,
	941850624,
	941867008,
	941883392,
	941899776,
	941916160,
	941932544,
	941948928,
	941965312,
	941981696,
	941998080,
	942014464,
	942030848,
	942047232,
	942063616,
	942080000,
	942096384,
	942112768,
	942129152,
	942145536,
	942161920,
	942178304,
	942194688,
	942211072,
	942227456,
	942243840,
	942260224,
	942276608,
	942292992,
	942309376,
	942325760,
	942342144,
	942358528,
	942374912,
	942391296,
	942407680,
	942424064,
	942440448,
	942456832,
	942473216,
	942489600,
	942505984,
	942522368,
	942538752,
	942555136,
	942571520,
	942587904,
	942604288,
	942620672,
	942637056,
	942653440,
	942669824,
	942686208,
	942702592,
	942718976,
	942735360,
	942751744,
	942768128,
	942784512,
	942800896,
	942817280,
	942833664,
	942850048,
	942866432,
	942882816,
	942899200,
	942915584,
	942931968,
	942948352,
	942964736,
	942981120,
	942997504,
	943013888,
	943030272,
	943046656,
	943063040,
	943079424,
	943095808,
	943112192,
	943128576,
	943144960,
	943161344,
	943177728,
	943194112,
	943210496,
	943226880,
	943243264,
	943259648,
	943276032,
	943292416,
	943308800,
	943325184,
	943341568,
	943357952,
	943374336,
	943390720,
	943407104,
	943423488,
	943439872,
	943456256,
	943472640,
	943489024,
	943505408,
	943521792,
	943538176,
	943554560,
	943570944,
	943587328,
	943603712,
	943620096,
	943636480,
	943652864,
	943669248,
	943685632,
	943702016,
	943718400,
	943734784,
	943751168,
	943767552,
	943783936,
	943800320,
	943816704,
	943833088,
	943849472,
	943865856,
	943882240,
	943898624,
	943915008,
	943931392,
	943947776,
	943964160,
	943980544,
	943996928,
	944013312,
	944029696,
	944046080,
	944062464,
	944078848,
	944095232,
	944111616,
	944128000,
	944144384,
	944160768,
	944177152,
	944193536,
	944209920,
	944226304,
	944242688,
	944259072,
	944275456,
	944291840,
	944308224,
	944324608,
	944340992,
	944357376,
	944373760,
	944390144,
	944406528,
	944422912,
	944439296,
	944455680,
	944472064,
	944488448,
	944504832,
	944521216,
	944537600,
	944553984,
	944570368,
	944586752,
	944603136,
	944619520,
	944635904,
	944652288,
	944668672,
	944685056,
	944701440,
	944717824,
	944734208,
	944750592,
	944766976,
	944783360,
	944799744,
	944816128,
	944832512,
	944848896,
	944865280,
	944881664,
	944898048,
	944914432,
	944930816,
	944947200,
	944963584,
	944979968,
	944996352,
	945012736,
	945029120,
	945045504,
	945061888,
	945078272,
	945094656,
	945111040,
	945127424,
	945143808,
	945160192,
	945176576,
	945192960,
	945209344,
	945225728,
	945242112,
	945258496,
	945274880,
	945291264,
	945307648,
	945324032,
	945340416,
	945356800,
	945373184,
	945389568,
	945405952,
	945422336,
	945438720,
	945455104,
	945471488,
	945487872,
	945504256,
	945520640,
	945537024,
	945553408,
	945569792,
	945586176,
	945602560,
	945618944,
	945635328,
	945651712,
	945668096,
	945684480,
	945700864,
	945717248,
	945733632,
	945750016,
	945766400,
	945782784,
	945799168,
	945815552,
	945831936,
	945848320,
	945864704,
	945881088,
	945897472,
	945913856,
	945930240,
	945946624,
	945963008,
	945979392,
	945995776,
	946012160,
	946028544,
	946044928,
	946061312,
	946077696,
	946094080,
	946110464,
	946126848,
	946143232,
	946159616,
	946176000,
	946192384,
	946208768,
	946225152,
	946241536,
	946257920,
	946274304,
	946290688,
	946307072,
	946323456,
	946339840,
	946356224,
	946372608,
	946388992,
	946405376,
	946421760,
	946438144,
	946454528,
	946470912,
	946487296,
	946503680,
	946520064,
	946536448,
	946552832,
	946569216,
	946585600,
	946601984,
	946618368,
	946634752,
	946651136,
	946667520,
	946683904,
	946700288,
	946716672,
	946733056,
	946749440,
	946765824,
	946782208,
	946798592,
	946814976,
	946831360,
	946847744,
	946864128,
	946880512,
	946896896,
	946913280,
	946929664,
	946946048,
	946962432,
	946978816,
	946995200,
	947011584,
	947027968,
	947044352,
	947060736,
	947077120,
	947093504,
	947109888,
	947126272,
	947142656,
	947159040,
	947175424,
	947191808,
	947208192,
	947224576,
	947240960,
	947257344,
	947273728,
	947290112,
	947306496,
	947322880,
	947339264,
	947355648,
	947372032,
	947388416,
	947404800,
	947421184,
	947437568,
	947453952,
	947470336,
	947486720,
	947503104,
	947519488,
	947535872,
	947552256,
	947568640,
	947585024,
	947601408,
	947617792,
	947634176,
	947650560,
	947666944,
	947683328,
	947699712,
	947716096,
	947732480,
	947748864,
	947765248,
	947781632,
	947798016,
	947814400,
	947830784,
	947847168,
	947863552,
	947879936,
	947896320,
	939524096,
	939532288,
	939540480,
	939548672,
	939556864,
	939565056,
	939573248,
	939581440,
	939589632,
	939597824,
	939606016,
	939614208,
	939622400,
	939630592,
	939638784,
	939646976,
	939655168,
	939663360,
	939671552,
	939679744,
	939687936,
	939696128,
	939704320,
	939712512,
	939720704,
	939728896,
	939737088,
	939745280,
	939753472,
	939761664,
	939769856,
	939778048,
	939786240,
	939794432,
	939802624,
	939810816,
	939819008,
	939827200,
	939835392,
	939843584,
	939851776,
	939859968,
	939868160,
	939876352,
	939884544,
	939892736,
	939900928,
	939909120,
	939917312,
	939925504,
	939933696,
	939941888,
	939950080,
	939958272,
	939966464,
	939974656,
	939982848,
	939991040,
	939999232,
	940007424,
	940015616,
	940023808,
	940032000,
	940040192,
	940048384,
	940056576,
	940064768,
	940072960,
	940081152,
	940089344,
	940097536,
	940105728,
	940113920,
	940122112,
	940130304,
	940138496,
	940146688,
	940154880,
	940163072,
	940171264,
	940179456,
	940187648,
	940195840,
	940204032,
	940212224,
	940220416,
	940228608,
	940236800,
	940244992,
	940253184,
	940261376,
	940269568,
	940277760,
	940285952,
	940294144,
	940302336,
	940310528,
	940318720,
	940326912,
	940335104,
	940343296,
	940351488,
	940359680,
	940367872,
	940376064,
	940384256,
	940392448,
	940400640,
	940408832,
	940417024,
	940425216,
	940433408,
	940441600,
	940449792,
	940457984,
	940466176,
	940474368,
	940482560,
	940490752,
	940498944,
	940507136,
	940515328,
	940523520,
	940531712,
	940539904,
	940548096,
	940556288,
	940564480,
	940572672,
	940580864,
	940589056,
	940597248,
	940605440,
	940613632,
	940621824,
	940630016,
	940638208,
	940646400,
	940654592,
	940662784,
	940670976,
	940679168,
	940687360,
	940695552,
	940703744,
	940711936,
	940720128,
	940728320,
	940736512,
	940744704,
	940752896,
	940761088,
	940769280,
	940777472,
	940785664,
	940793856,
	940802048,
	940810240,
	940818432,
	940826624,
	940834816,
	940843008,
	940851200,
	940859392,
	940867584,
	940875776,
	940883968,
	940892160,
	940900352,
	940908544,
	940916736,
	940924928,
	940933120,
	940941312,
	940949504,
	940957696,
	940965888,
	940974080,
	940982272,
	940990464,
	940998656,
	941006848,
	941015040,
	941023232,
	941031424,
	941039616,
	941047808,
	941056000,
	941064192,
	941072384,
	941080576,
	941088768,
	941096960,
	941105152,
	941113344,
	941121536,
	941129728,
	941137920,
	941146112,
	941154304,
	941162496,
	941170688,
	941178880,
	941187072,
	941195264,
	941203456,
	941211648,
	941219840,
	941228032,
	941236224,
	941244416,
	941252608,
	941260800,
	941268992,
	941277184,
	941285376,
	941293568,
	941301760,
	941309952,
	941318144,
	941326336,
	941334528,
	941342720,
	941350912,
	941359104,
	941367296,
	941375488,
	941383680,
	941391872,
	941400064,
	941408256,
	941416448,
	941424640,
	941432832,
	941441024,
	941449216,
	941457408,
	941465600,
	941473792,
	941481984,
	941490176,
	941498368,
	941506560,
	941514752,
	941522944,
	941531136,
	941539328,
	941547520,
	941555712,
	941563904,
	941572096,
	941580288,
	941588480,
	941596672,
	941604864,
	941613056,
	941621248,
	941629440,
	941637632,
	941645824,
	941654016,
	941662208,
	941670400,
	941678592,
	941686784,
	941694976,
	941703168,
	941711360,
	941719552,
	941727744,
	941735936,
	941744128,
	941752320,
	941760512,
	941768704,
	941776896,
	941785088,
	941793280,
	941801472,
	941809664,
	941817856,
	941826048,
	941834240,
	941842432,
	941850624,
	941858816,
	941867008,
	941875200,
	941883392,
	941891584,
	941899776,
	941907968,
	941916160,
	941924352,
	941932544,
	941940736,
	941948928,
	941957120,
	941965312,
	941973504,
	941981696,
	941989888,
	941998080,
	942006272,
	942014464,
	942022656,
	942030848,
	942039040,
	942047232,
	942055424,
	942063616,
	942071808,
	942080000,
	942088192,
	942096384,
	942104576,
	942112768,
	942120960,
	942129152,
	942137344,
	942145536,
	942153728,
	942161920,
	942170112,
	942178304,
	942186496,
	942194688,
	942202880,
	942211072,
	942219264,
	942227456,
	942235648,
	942243840,
	942252032,
	942260224,
	942268416,
	942276608,
	942284800,
	942292992,
	942301184,
	942309376,
	942317568,
	942325760,
	942333952,
	942342144,
	942350336,
	942358528,
	942366720,
	942374912,
	942383104,
	942391296,
	942399488,
	942407680,
	942415872,
	942424064,
	942432256,
	942440448,
	942448640,
	942456832,
	942465024,
	942473216,
	942481408,
	942489600,
	942497792,
	942505984,
	942514176,
	942522368,
	942530560,
	942538752,
	942546944,
	942555136,
	942563328,
	942571520,
	942579712,
	942587904,
	942596096,
	942604288,
	942612480,
	942620672,
	942628864,
	942637056,
	942645248,
	942653440,
	942661632,
	942669824,
	942678016,
	942686208,
	942694400,
	942702592,
	942710784,
	942718976,
	942727168,
	942735360,
	942743552,
	942751744,
	942759936,
	942768128,
	942776320,
	942784512,
	942792704,
	942800896,
	942809088,
	942817280,
	942825472,
	942833664,
	942841856,
	942850048,
	942858240,
	942866432,
	942874624,
	942882816,
	942891008,
	942899200,
	942907392,
	942915584,
	942923776,
	942931968,
	942940160,
	942948352,
	942956544,
	942964736,
	942972928,
	942981120,
	942989312,
	942997504,
	943005696,
	943013888,
	943022080,
	943030272,
	943038464,
	943046656,
	943054848,
	943063040,
	943071232,
	943079424,
	943087616,
	943095808,
	943104000,
	943112192,
	943120384,
	943128576,
	943136768,
	943144960,
	943153152,
	943161344,
	943169536,
	943177728,
	943185920,
	943194112,
	943202304,
	943210496,
	943218688,
	943226880,
	943235072,
	943243264,
	943251456,
	943259648,
	943267840,
	943276032,
	943284224,
	943292416,
	943300608,
	943308800,
	943316992,
	943325184,
	943333376,
	943341568,
	943349760,
	943357952,
	943366144,
	943374336,
	943382528,
	943390720,
	943398912,
	943407104,
	943415296,
	943423488,
	943431680,
	943439872,
	943448064,
	943456256,
	943464448,
	943472640,
	943480832,
	943489024,
	943497216,
	943505408,
	943513600,
	943521792,
	943529984,
	943538176,
	943546368,
	943554560,
	943562752,
	943570944,
	943579136,
	943587328,
	943595520,
	943603712,
	943611904,
	943620096,
	943628288,
	943636480,
	943644672,
	943652864,
	943661056,
	943669248,
	943677440,
	943685632,
	943693824,
	943702016,
	943710208,
	943718400,
	943726592,
	943734784,
	943742976,
	943751168,
	943759360,
	943767552,
	943775744,
	943783936,
	943792128,
	943800320,
	943808512,
	943816704,
	943824896,
	943833088,
	943841280,
	943849472,
	943857664,
	943865856,
	943874048,
	943882240,
	943890432,
	943898624,
	943906816,
	943915008,
	943923200,
	943931392,
	943939584,
	943947776,
	943955968,
	943964160,
	943972352,
	943980544,
	943988736,
	943996928,
	944005120,
	944013312,
	944021504,
	944029696,
	944037888,
	944046080,
	944054272,
	944062464,
	944070656,
	944078848,
	944087040,
	944095232,
	944103424,
	944111616,
	944119808,
	944128000,
	944136192,
	944144384,
	944152576,
	944160768,
	944168960,
	944177152,
	944185344,
	944193536,
	944201728,
	944209920,
	944218112,
	944226304,
	944234496,
	944242688,
	944250880,
	944259072,
	944267264,
	944275456,
	944283648,
	944291840,
	944300032,
	944308224,
	944316416,
	944324608,
	944332800,
	944340992,
	944349184,
	944357376,
	944365568,
	944373760,
	944381952,
	944390144,
	944398336,
	944406528,
	944414720,
	944422912,
	944431104,
	944439296,
	944447488,
	944455680,
	944463872,
	944472064,
	944480256,
	944488448,
	944496640,
	944504832,
	944513024,
	944521216,
	944529408,
	944537600,
	944545792,
	944553984,
	944562176,
	944570368,
	944578560,
	944586752,
	944594944,
	944603136,
	944611328,
	944619520,
	944627712,
	944635904,
	944644096,
	944652288,
	944660480,
	944668672,
	944676864,
	944685056,
	944693248,
	944701440,
	944709632,
	944717824,
	944726016,
	944734208,
	944742400,
	944750592,
	944758784,
	944766976,
	944775168,
	944783360,
	944791552,
	944799744,
	944807936,
	944816128,
	944824320,
	944832512,
	944840704,
	944848896,
	944857088,
	944865280,
	944873472,
	944881664,
	944889856,
	944898048,
	944906240,
	944914432,
	944922624,
	944930816,
	944939008,
	944947200,
	944955392,
	944963584,
	944971776,
	944979968,
	944988160,
	944996352,
	945004544,
	945012736,
	945020928,
	945029120,
	945037312,
	945045504,
	945053696,
	945061888,
	945070080,
	945078272,
	945086464,
	945094656,
	945102848,
	945111040,
	945119232,
	945127424,
	945135616,
	945143808,
	945152000,
	945160192,
	945168384,
	945176576,
	945184768,
	945192960,
	945201152,
	945209344,
	945217536,
	945225728,
	945233920,
	945242112,
	945250304,
	945258496,
	945266688,
	945274880,
	945283072,
	945291264,
	945299456,
	945307648,
	945315840,
	945324032,
	945332224,
	945340416,
	945348608,
	945356800,
	945364992,
	945373184,
	945381376,
	945389568,
	945397760,
	945405952,
	945414144,
	945422336,
	945430528,
	945438720,
	945446912,
	945455104,
	945463296,
	945471488,
	945479680,
	945487872,
	945496064,
	945504256,
	945512448,
	945520640,
	945528832,
	945537024,
	945545216,
	945553408,
	945561600,
	945569792,
	945577984,
	945586176,
	945594368,
	945602560,
	945610752,
	945618944,
	945627136,
	945635328,
	945643520,
	945651712,
	945659904,
	945668096,
	945676288,
	945684480,
	945692672,
	945700864,
	945709056,
	945717248,
	945725440,
	945733632,
	945741824,
	945750016,
	945758208,
	945766400,
	945774592,
	945782784,
	945790976,
	945799168,
	945807360,
	945815552,
	945823744,
	945831936,
	945840128,
	945848320,
	945856512,
	945864704,
	945872896,
	945881088,
	945889280,
	945897472,
	945905664,
	945913856,
	945922048,
	945930240,
	945938432,
	945946624,
	945954816,
	945963008,
	945971200,
	945979392,
	945987584,
	945995776,
	946003968,
	946012160,
	946020352,
	946028544,
	946036736,
	946044928,
	946053120,
	946061312,
	946069504,
	946077696,
	946085888,
	946094080,
	946102272,
	946110464,
	946118656,
	946126848,
	946135040,
	946143232,
	946151424,
	946159616,
	946167808,
	946176000,
	946184192,
	946192384,
	946200576,
	946208768,
	946216960,
	946225152,
	946233344,
	946241536,
	946249728,
	946257920,
	946266112,
	946274304,
	946282496,
	946290688,
	946298880,
	946307072,
	946315264,
	946323456,
	946331648,
	946339840,
	946348032,
	946356224,
	946364416,
	946372608,
	946380800,
	946388992,
	946397184,
	946405376,
	946413568,
	946421760,
	946429952,
	946438144,
	946446336,
	946454528,
	946462720,
	946470912,
	946479104,
	946487296,
	946495488,
	946503680,
	946511872,
	946520064,
	946528256,
	946536448,
	946544640,
	946552832,
	946561024,
	946569216,
	946577408,
	946585600,
	946593792,
	946601984,
	946610176,
	946618368,
	946626560,
	946634752,
	946642944,
	946651136,
	946659328,
	946667520,
	946675712,
	946683904,
	946692096,
	946700288,
	946708480,
	946716672,
	946724864,
	946733056,
	946741248,
	946749440,
	946757632,
	946765824,
	946774016,
	946782208,
	946790400,
	946798592,
	946806784,
	946814976,
	946823168,
	946831360,
	946839552,
	946847744,
	946855936,
	946864128,
	946872320,
	946880512,
	946888704,
	946896896,
	946905088,
	946913280,
	946921472,
	946929664,
	946937856,
	946946048,
	946954240,
	946962432,
	946970624,
	946978816,
	946987008,
	946995200,
	947003392,
	947011584,
	947019776,
	947027968,
	947036160,
	947044352,
	947052544,
	947060736,
	947068928,
	947077120,
	947085312,
	947093504,
	947101696,
	947109888,
	947118080,
	947126272,
	947134464,
	947142656,
	947150848,
	947159040,
	947167232,
	947175424,
	947183616,
	947191808,
	947200000,
	947208192,
	947216384,
	947224576,
	947232768,
	947240960,
	947249152,
	947257344,
	947265536,
	947273728,
	947281920,
	947290112,
	947298304,
	947306496,
	947314688,
	947322880,
	947331072,
	947339264,
	947347456,
	947355648,
	947363840,
	947372032,
	947380224,
	947388416,
	947396608,
	947404800,
	947412992,
	947421184,
	947429376,
	947437568,
	947445760,
	947453952,
	947462144,
	947470336,
	947478528,
	947486720,
	947494912,
	947503104,
	947511296,
	947519488,
	947527680,
	947535872,
	947544064,
	947552256,
	947560448,
	947568640,
	947576832,
	947585024,
	947593216,
	947601408,
	947609600,
	947617792,
	947625984,
	947634176,
	947642368,
	947650560,
	947658752,
	947666944,
	947675136,
	947683328,
	947691520,
	947699712,
	947707904,
	947716096,
	947724288,
	947732480,
	947740672,
	947748864,
	947757056,
	947765248,
	947773440,
	947781632,
	947789824,
	947798016,
	947806208,
	947814400,
	947822592,
	947830784,
	947838976,
	947847168,
	947855360,
	947863552,
	947871744,
	947879936,
	947888128,
	947896320,
	947904512,
};

unsigned int HalfFloat::exponent_table[64] =
{
	0,
	8388608,
	16777216,
	25165824,
	33554432,
	41943040,
	50331648,
	58720256,
	67108864,
	75497472,
	83886080,
	92274688,
	100663296,
	109051904,
	117440512,
	125829120,
	134217728,
	142606336,
	150994944,
	159383552,
	167772160,
	176160768,
	184549376,
	192937984,
	201326592,
	209715200,
	218103808,
	226492416,
	234881024,
	243269632,
	251658240,
	1199570944,
	2147483648,
	2155872256,
	2164260864,
	2172649472,
	2181038080,
	2189426688,
	2197815296,
	2206203904,
	2214592512,
	2222981120,
	2231369728,
	2239758336,
	2248146944,
	2256535552,
	2264924160,
	2273312768,
	2281701376,
	2290089984,
	2298478592,
	2306867200,
	2315255808,
	2323644416,
	2332033024,
	2340421632,
	2348810240,
	2357198848,
	2365587456,
	2373976064,
	2382364672,
	2390753280,
	2399141888,
	3347054592,
};

unsigned short HalfFloat::offset_table[64] =
{
	0,
	1024,
	1024,
	1024,
	1024,
	1024,
	1024,
	1024,
	1024,
	1024,
	1024,
	1024,
	1024,
	1024,
	1024,
	1024,
	1024,
	1024,
	1024,
	1024,
	1024,
	1024,
	1024,
	1024,
	1024,
	1024,
	1024,
	1024,
	1024,
	1024,
	1024,
	1024,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
};

unsigned short HalfFloat::base_table[512] =
{
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	1,
	2,
	4,
	8,
	16,
	32,
	64,
	128,
	256,
	512,
	1024,
	2048,
	3072,
	4096,
	5120,
	6144,
	7168,
	8192,
	9216,
	10240,
	11264,
	12288,
	13312,
	14336,
	15360,
	16384,
	17408,
	18432,
	19456,
	20480,
	21504,
	22528,
	23552,
	24576,
	25600,
	26624,
	27648,
	28672,
	29696,
	30720,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	31744,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32768,
	32769,
	32770,
	32772,
	32776,
	32784,
	32800,
	32832,
	32896,
	33024,
	33280,
	33792,
	34816,
	35840,
	36864,
	37888,
	38912,
	39936,
	40960,
	41984,
	43008,
	44032,
	45056,
	46080,
	47104,
	48128,
	49152,
	50176,
	51200,
	52224,
	53248,
	54272,
	55296,
	56320,
	57344,
	58368,
	59392,
	60416,
	61440,
	62464,
	63488,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
	64512,
};

unsigned char HalfFloat::shift_table[512] =
{
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	23,
	22,
	21,
	20,
	19,
	18,
	17,
	16,
	15,
	14,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	13,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	23,
	22,
	21,
	20,
	19,
	18,
	17,
	16,
	15,
	14,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	13,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	24,
	13,
};

/*

void generate_tables()
{
	unsigned int mantissa_table[2048];
	unsigned int exponent_table[64];
	unsigned short offset_table[64];
	unsigned short base_table[512];
	unsigned char shift_table[512];

	mantissa_table[0] = 0;
	for (int i = 1; i < 1024; i++)
	{
		unsigned int m=i<<13; // Zero pad mantissa bits
		unsigned int e=0; // Zero exponent
		while(!(m&0x00800000)) // While not normalized
		{
			e-=0x00800000; // Decrement exponent (1<<23)
			m<<=1; // Shift mantissa
		}
		m&=~0x00800000; // Clear leading 1 bit
		e+=0x38800000; // Adjust bias ((127-14)<<23)
		mantissa_table[i] = m | e;
	}
	for (int i = 1024; i < 2048; i++)
	{
		mantissa_table[i] = 0x38000000 + ((i - 1024) << 13);
	}

	exponent_table[0] = 0;
	exponent_table[32] = 0x80000000;

	for (int i = 1; i < 31; i++)
		exponent_table[i] = i<<23;
	for (int i = 33; i < 63; i++)
		exponent_table[i] = 0x80000000 + ((i-32)<<23);

	exponent_table[31] = 0x47800000;
	exponent_table[63] = 0xC7800000;

	offset_table[0] = 0;
	offset_table[32] = 0;
	for (int i = 1; i < 32; i++)
		offset_table[i] = 1024;

	for(unsigned int i=0; i<256; ++i)
	{
		int e=i-127;
		if (e<-24) // Very small numbers map to zero
		{
			base_table[i|0x000]=0x0000;
			base_table[i|0x100]=0x8000;
			shift_table[i|0x000]=24;
			shift_table[i|0x100]=24;
		}
		else if (e<-14) // Small numbers map to denorms
		{
			base_table[i|0x000]=(0x0400>>(-e-14));
			base_table[i|0x100]=(0x0400>>(-e-14)) | 0x8000;
			shift_table[i|0x000]=-e-1;
			shift_table[i|0x100]=-e-1;
		}
		else if (e<=15) // Normal numbers just lose precision
		{
			base_table[i|0x000]=((e+15)<<10);
			base_table[i|0x100]=((e+15)<<10) | 0x8000;
			shift_table[i|0x000]=13;
			shift_table[i|0x100]=13;
		}
		else if (e<128) // Large numbers map to Infinity
		{
			base_table[i|0x000]=0x7C00;
			base_table[i|0x100]=0xFC00;
			shift_table[i|0x000]=24;
			shift_table[i|0x100]=24;
		}
		else // Infinity and NaN's stay Infinity and NaN's
		{
			base_table[i|0x000]=0x7C00;
			base_table[i|0x100]=0xFC00;
			shift_table[i|0x000]=13;
			shift_table[i|0x100]=13;
		}
	}

	File file("tables.txt", File::create_always, File::access_read_write);
	file.write_string_text("unsigned int HalfFloat::mantissa_table[2048] =");
	file.write_string_text("{");
	for (int i = 0; i < 2048; i++)
	{
		file.write_string_text("\t" + StringHelp::uint_to_text(mantissa_table[i]) + ",");
	}
	file.write_string_text("};");
	file.write_string_text("");

	file.write_string_text("unsigned int HalfFloat::exponent_table[64] =");
	file.write_string_text("{");
	for (int i = 0; i < 64; i++)
	{
		file.write_string_text("\t" + StringHelp::uint_to_text(exponent_table[i]) + ",");
	}
	file.write_string_text("};");
	file.write_string_text("");

	file.write_string_text("unsigned short HalfFloat::offset_table[64] =");
	file.write_string_text("{");
	for (int i = 0; i < 64; i++)
	{
		file.write_string_text("\t" + StringHelp::uint_to_text(offset_table[i]) + ",");
	}
	file.write_string_text("};");
	file.write_string_text("");

	file.write_string_text("unsigned short HalfFloat::base_table[512] =");
	file.write_string_text("{");
	for (int i = 0; i < 512; i++)
	{
		file.write_string_text("\t" + StringHelp::uint_to_text(base_table[i]) + ",");
	}
	file.write_string_text("};");
	file.write_string_text("");

	file.write_string_text("unsigned char HalfFloat::shift_table[512] =");
	file.write_string_text("{");
	for (int i = 0; i < 512; i++)
	{
		file.write_string_text("\t" + StringHelp::uint_to_text(shift_table[i]) + ",");
	}
	file.write_string_text("};");
	file.write_string_text("");
}
*/

}
