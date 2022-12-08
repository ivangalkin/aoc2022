#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <tuple>
#include <numeric>
#include <algorithm>

#ifdef NDEBUG
#undef NDEBUG
#endif

#include <assert.h>

#define ASSERT_EQ(a, b) \
   do { __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     if (_a != _b)       \
     {                 \
       std::cout << _a << " != " << _b << std::endl; \
       assert(0);                  \
     }                  \
     }while(0)

namespace {
    std::vector<std::string> input_real = {
            "211332213033101124130110410025404035324540506465522424325025442423205322144201114032433102223133301",
            "311023320242030112033354205533003100224166354233554634221041635230051410343235342432112434034030100",
            "001223204433022013103305410222315554032366506021405002315044463420051033302201255133143124420412122",
            "013132233012344225535033304112253201303421563422623305021204605543621044544210352330412212401012131",
            "123203213200414113431324051024435265606056206220330353405664413252121241340014021504043322022404322",
            "300314334303200324110001011065050624136654044030061620050042314252632633325011034021521210022442213",
            "300312304313121233203544305130444460463436450145663611020201513406316245230444434551201440322230302",
            "121213330224031553422231036233163250606241600057176176344004346462440003006410044502531341130240114",
            "301324240431503125500116062453142425154655731122643437177477550414605433012615301235013252120302340",
            "003232040401112004305510155520121504621467762731313536577767114335412665224212525123530315344321124",
            "020011211014152120140622132315236133565515235564134376673433256457543305603063000545505055054420401",
            "120232244154134255122415053246324763251764537642172244222741232566733246632230131225000041540131403",
            "340032215420250553142064146064564173357273533153247735663417273646632371434553560636420004452544143",
            "043414443322552422161330440067615566131775467414772511621257632542341175313336105314043250123012200",
            "012111021442304652102413106134662444516476275112834287667673516365611433432545515260120211024041202",
            "032102521544554062032010572477745124332575337882847632625227237576235753415421361112101043554053100",
            "311444312333365122206150371721763624374376873885257652577482877454566142635223501265056342151423503",
            "144251432134413522432634164521765222778875228537684473757528335574576764563372055450540131505303034",
            "000255023251250523115357427615753523575838766845363763466455836854431647317161446453545305422435355",
            "245002340133321145325367575315512257574665372575562748686454783577847666453745464626164131031332100",
            "050553025366530325021416326145857322624322772785872882346577742678858344161622134432426516051344250",
            "152311521001545435344376115464326457845848454437444432763844343744467358574522513450314302061503452",
            "432454304206244265363237124475585684786823237698738473868377345823852284311544625730363140211242142",
            "454020453313433443537657634364823277466449658493374864768899457268665377243765726567464021363445250",
            "552431324265025566426217457328875767435899547855738449793664649385627243287213716374361136462440243",
            "031052136256223525442167246873557667773568893448343999893549698865743526327856612255315524012102000",
            "345323665312406654514446384583427637865769666594853994657493368533935635676521153437537311305202142",
            "342110244050561175476152877378374945653376889649978659538759435748334872266574665131763066015150414",
            "145433434262576274652174742347844566354377337849447759743936477456984862853785777171357505003212025",
            "310242523113472175765257374582489598876797985649454666865333776554339348242882833175411762344652012",
            "434056456416337446635277274487757585458766758586996458774953698859555746353645282477417311113216435",
            "045021105500376267478536827836355597677975786498896678587684858536744539776275465227567675153251405",
            "300142642025442446482242442484398879535896799784784778494989949379689755588234538855243763305416321",
            "353622636633651765254457642339454687946896697548485487765646998666995567567726837277556747624363451",
            "202435626512143732835284377793378475946599964657457656969997944856356445774883877827536725303005505",
            "135650034646464156744647526498458647549464945549765974544889665765659884799642263733421214426362624",
            "150435334074657468688563599355379375877984576587798777599554755799738577897957837453257132312302144",
            "512443536422754252577234434969994856586456545889988865785958887667666384435563246262331235420111143",
            "466652116227352685834266983738374448949754669575866999669685556447597478636534623278751113456645060",
            "021164506132145534653735865996437996949669685788777975556657797445847474955965558246253533611024642",
            "231050262356423276576326937834369549887967896966756856658985767688875977398375688846413232324304226",
            "435212106653324768273769678978879679954786766976999558656777959955869577458834883774845467247506214",
            "160366254415742474477255579484597574496859676569755788769767586676674847997944768266836256767533110",
            "241513312227373552852675497876868858749576878555778658557589787666975955754559662763784164711060064",
            "351110451267671255426564695657766766686759856878789989756858799968497958544598723587586767222266454",
            "316062153252225354662464658785786565488858687886778777967566595898554596936489753547456317121214424",
            "212536666162371857232636965378959948576758567679878996998888878797474958786685542845571126616220264",
            "510024546261143787272349466837799649568665658866988878698565865894746985377749787572341577611344166",
            "004351216364728646844848837567468684779987996888767898677985599854955668566559858835633322134522334",
            "336463436447757363543649949947564678786988588988866877968758989665477866657945447564627357126653146",
            "026065162577657624222467836757949464596556769778678999898769595755945784554668326364364774614112042",
            "503221631577514777533445365468588455658986887687687789867975758885748889857396423825776253156736650",
            "546513661435242553764893754934757584678877997789877686967898678564676598335965867335727137112215030",
            "611265646576763532336777659499858694897877758999678876979977887874768566899568336424484421461153426",
            "354632527555434648642259948845976658869997857679769998977895558994584876439733545486722237134252244",
            "520066365142477526347774786479494548687879769997669786998678978895445886967346756354286727222124503",
            "036426316533162875778686487545896556958758868879977868686688986574849753898677468557551537174650421",
            "560265634575463724567588788767856667457699558755596657566679586798788873437533663746231724155125525",
            "154560626115545678446889538386759776485985597568577777558958786887687647784334647726551367164130624",
            "435604614267661345622839365943384759557699679885767759599566796964556464635883224855517743254442610",
            "015330201727631536234389975658784474799697966578756955569957997995994446883848582283235113446522166",
            "352230033476456648636532764835957899749588885668565677958598595585884536843566635235535143233400362",
            "154324641154514622554238347338736749648497879886988865566875744965765539565765428586545254520653004",
            "453036521326216338225852566856869755589995557886678566578454876595677374667726383554235644733043120",
            "255116155525323462526438743774389777499948654465588776697977856998545943966845458742427155331033531",
            "025560625413477123376683438634566738565665455954779575658546654745567665935272473226176343466230234",
            "024466546555224254763532784959665896878967666774886569787656978898736887735524866681527476335351660",
            "431553605003462632355435287785653379467565865846957764769957785898849746583877462511543675401304331",
            "245166660214751253743856378267388633494584489567844846476445548983654883554368632374551522612226505",
            "540335146233545626252387487873545495675665748448745979949594735654895943368867237133447443126433414",
            "234255620120615565122843883767337363659787964676878598696674776783394766454355878652417710601552535",
            "155234425620263264536252385765564357733857634857584669678763477778599626835456677357151640115601402",
            "415011642631335751527728632365876445738339479934933867368973986563564488774233653717376514142421112",
            "331553124665647777751514436356443477749885879596563793484897353687466437233338475237523161110142051",
            "125403316650422145565532565656426288343597345985455577884935753554564626425235737254643554446160112",
            "244245221040325667524534344843767845646457957737955963874753776775484255785447725731356435212213414",
            "502435004653346035253622224342447486734347953679733888847856349544574634822773162422363261331201024",
            "324222044306505016426445557827266762373537588855883779693953564587846832687121422621334643504041214",
            "242441310622432165134457161657567575877727367394894947493553362876526782815233251471504221505502531",
            "404413131464141606677317644575735753536548433834477734384655752565382465763337735513154564140342251",
            "301100110415420444111615617662387653344875842557335485555688447688575465433323177644556524120212234",
            "121350153052662132322721116134216553883566368426252878468274827563855654437763154152652520055535413",
            "300411255204026610413574577661773545843284364682683778487466278862352135457325560155622450041155414",
            "201513150243444362415017756317333176455677876825338686288332246436653511332623525023535335010251403",
            "442151212200240012240515354421652475542422627327336365453756577274176715121634500306606230505005442",
            "221142355114024136331532344422671215757576745773483847686535252141745132161123140234155444022141343",
            "303111241400254212624566606371413763653433175765433383216314527571326314157614031441404441454123113",
            "244200502534242261362202215053674434622174351252464554756217534657676575631240166556655421245234022",
            "033140410031001244605126654665654443346166177754221527272665473526726632645640155606531431321003203",
            "333144020203540344460212034601443662327775175627432461421467275253741652534221451541150344324122432",
            "003441144232331144321240262132134156264312772115415535174111161372132213423063330000551314401242014",
            "431244213034140532345020014016302213467251277744712151733426334265042000625105541402423314424042442",
            "032332242311014553503456362533135654462331252577334743117656122022210110152631423434352520024421043",
            "102103002322052451100230340420161635556642503226271246652053202351054222634613532434255202434131242",
            "203130013133233045044204223404060632403351664241443631454330322650226245651432113040525413323340210",
            "030124200340221230241225521446452652313241114064226552054332165233441366221221035421132414124314402",
            "120112413030344114412231514332254000023525634236200334160045616312416360423100451201322404023012301",
            "212011312011233130523111525121303414244121320644050343211556336246463215444025331411002041412122121",
            "002023323443102242311523000140150506160522004635222556200251663551444551235250440223242010414011021"
    };

    auto &input = input_real;
    int64_t SIZE = input.size();

    int64_t value(int64_t x, int64_t y) {
        return input.at(y).at(x) - '0';
    }

    bool check(int64_t x, int64_t y) {
        auto v = value(x, y);
        {
            int64_t MAX_LEFT = INT64_MIN;
            for (int64_t i = 0; i < x; i++) {
                MAX_LEFT = std::max(value(i, y), MAX_LEFT);
            }
            if (v > MAX_LEFT) {
                return true;
            }
        }
        {
            int64_t MAX_RIGHT = INT64_MIN;
            for (int64_t i = x + 1; i < SIZE; i++) {
                MAX_RIGHT = std::max(value(i, y), MAX_RIGHT);
            }
            if (v > MAX_RIGHT) {
                return true;
            }
        }
        {
            int64_t MAX_TOP = INT64_MIN;
            for (int64_t j = 0; j < y; j++) {
                MAX_TOP = std::max(value(x, j), MAX_TOP);
            }
            if (v > MAX_TOP) {
                return true;
            }
        }
        {
            int64_t MAX_BOTTOM = INT64_MIN;
            for (int64_t j = y + 1; j < SIZE; j++) {
                MAX_BOTTOM = std::max(value(x, j), MAX_BOTTOM);
            }
            if (v > MAX_BOTTOM) {
                return true;
            }
        }

        return false;
    }

    int64_t score(int64_t x, int64_t y) {
        auto my_v = value(x, y);
        int64_t left = 0;
        int64_t right = 0;
        int64_t top = 0;
        int64_t bottom = 0;
        for (int64_t i = x - 1; i >= 0; i--) {
            left++;
            if (my_v <= value(i, y)) {
                break;
            }
        }
        for (int64_t i = x + 1; i < SIZE; i++) {
            right++;
            if (my_v <= value(i, y)) {
                break;
            }
        }
        for (int64_t j = y - 1; j >= 0; j--) {
            top++;
            if (my_v <= value(x, j)) {
                break;
            }
        }
        for (int64_t j = y + 1; j < SIZE; j++) {
            bottom++;
            if (my_v <= value(x, j)) {
                break;
            }
        }
        return left * right * top * bottom;
    }
}

int _8() {
    int64_t result0 = 0;
    int64_t result1 = 0;

    ASSERT_EQ(SIZE, input.at(0).length());
    for (int64_t j = 0; j < SIZE; j++) {
        for (int64_t i = 0; i < SIZE; i++) {
            auto visible = check(i, j);
            result0 += visible;
        }
    }

    for (int64_t j = 0; j < SIZE; j++) {
        for (int64_t i = 0; i < SIZE; i++) {
            auto s = score(i, j);
            result1 = std::max(result1, s);
        }
    }

    std::cout << result0 << std::endl;
    std::cout << result1 << std::endl;
    return 0;
}
