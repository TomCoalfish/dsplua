const float g_input[] = {0.3745401203632355f, 0.9507142901420593f, 0.7319939136505127f, 0.5986585021018982f, 0.15601864457130432f, 0.15599451959133148f, 0.058083612471818924f, 0.8661761283874512f, 0.6011149883270264f, 0.7080726027488708f, 0.02058449387550354f, 0.9699098467826843f, 0.8324426412582397f, 0.2123391181230545f, 0.1818249672651291f, 0.18340450525283813f, 0.30424225330352783f, 0.5247564315795898f, 0.4319450259208679f, 0.29122912883758545f, 0.6118528842926025f, 0.13949386775493622f, 0.29214465618133545f, 0.3663618564605713f, 0.4560699760913849f, 0.7851759791374207f, 0.19967378675937653f, 0.5142344236373901f, 0.5924145579338074f, 0.0464504137635231f, 0.6075448393821716f, 0.17052412033081055f, 0.0650515928864479f, 0.9488855600357056f, 0.9656320214271545f, 0.8083973526954651f, 0.30461376905441284f, 0.09767211228609085f, 0.6842330098152161f, 0.44015249609947205f, 0.12203823775053024f, 0.49517691135406494f, 0.03438851982355118f, 0.9093204140663147f, 0.25877997279167175f, 0.6625222563743591f, 0.31171107292175293f, 0.5200680494308472f, 0.5467102527618408f, 0.18485446274280548f, 0.9695846438407898f, 0.7751328349113464f, 0.9394989609718323f, 0.8948273658752441f, 0.5978999733924866f, 0.9218742251396179f, 0.0884925052523613f, 0.19598285853862762f, 0.0452272891998291f, 0.32533031702041626f, 0.38867729902267456f, 0.2713490426540375f, 0.8287374973297119f, 0.35675331950187683f, 0.28093451261520386f, 0.5426960587501526f, 0.14092423021793365f, 0.8021969795227051f, 0.07455064356327057f, 0.9868869185447693f, 0.7722447514533997f, 0.1987156867980957f, 0.005522117018699646f, 0.8154614567756653f, 0.7068573236465454f, 0.7290071845054626f, 0.7712703347206116f, 0.07404465228319168f, 0.3584657311439514f, 0.11586906015872955f};
const float g_reference[] = {0.3745401203632355f, 2.43902254504441f, 3.000485599386873f, 3.3342675258797465f, 1.0838691675040915f, 0.15599451959133148f, 0.14901137153962477f, 3.5505062969691297f, 3.347949085933531f, 4.9190150611975545f, 0.02058449387550354f, 2.4882680396126733f, 3.412230772458926f, 1.18263655079793f, 1.2631469555617523f, 0.18340450525283813f, 0.7805223111262334f, 2.151007114646519f, 2.4057459600700604f, 2.0231830259355563f, 0.6118528842926025f, 0.3578663872811827f, 1.197517926670144f, 2.040476225475169f, 3.1683404676923974f, 0.7851759791374207f, 0.5122557561302025f, 2.1078767924970396f, 3.29949147208618f, 0.32269330011440367f, 0.6075448393821716f, 0.4374733590031192f, 0.26665026038202194f, 5.284879939890589f, 6.708292961109612f, 0.8083973526954651f, 0.7814754211211533f, 0.40036366547719043f, 3.810880321171002f, 3.0577609543592152f, 0.12203823775053024f, 1.2703581539702695f, 0.1409605415982451f, 5.0645192820209415f, 1.7977571491351656f, 0.6625222563743591f, 0.799683293161119f, 2.131789163705411f, 3.0449383671144123f, 1.2841930090662477f, 0.9695846438407898f, 1.9885747793592805f, 3.851060849640902f, 4.983799305999835f, 4.15364040748002f, 0.9218742251396179f, 0.22702426755962526f, 0.8033451287036053f, 0.25189633344068696f, 2.2600856509274885f, 0.38867729902267456f, 0.6961359889841584f, 3.397043172133452f, 1.986960852954598f, 1.9516658226847146f, 0.5426960587501526f, 0.36153592957271036f, 3.288252046968146f, 0.41521466577975596f, 6.855951772705847f, 0.7722447514533997f, 0.5097977859174891f, 0.022635478634113717f, 4.541765705134667f, 4.910572457734731f, 0.7290071845054626f, 1.9786656771788211f, 0.30351333357315186f, 1.9964982411467993f, 0.8049480375810305f};
const size_t k_nframes = 16;
const size_t k_ncoeffs = 5;