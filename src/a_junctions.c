#include "a_junctions.h"
#include "arsi.h"

// clang-format off
p_t *ο;I(iε,
"ο", ο,              L)IN(L,
init_mc21,      import);

N(ada);


#define JUN(Tail, Name, Jun, Head) N(Name) { A(Jun) ada(T()); } EN(Tail, Name, Head)
JUN(tail,
and        , 0010, L)JUN(L,
and2       , 0020, L)JUN(L,
and2or     , 0021, L)JUN(L,
and2or2    , 0022, L)JUN(L,
and2or3    , 0023, L)JUN(L,
and2or4    , 0024, L)JUN(L,
and2or5    , 0025, L)JUN(L,
and2or6    , 0026, L)JUN(L,
and2or7    , 0027, L)JUN(L,
and3       , 0030, L)JUN(L,
and3or     , 0031, L)JUN(L,
and3or2    , 0032, L)JUN(L,
and3or3    , 0033, L)JUN(L,
and3or4    , 0034, L)JUN(L,
and3or5    , 0035, L)JUN(L,
and3or6    , 0036, L)JUN(L,
and3or7    , 0037, L)JUN(L,
and4       , 0040, L)JUN(L,
and4or     , 0041, L)JUN(L,
and4or2    , 0042, L)JUN(L,
and4or3    , 0043, L)JUN(L,
and4or4    , 0044, L)JUN(L,
and4or5    , 0045, L)JUN(L,
and4or6    , 0046, L)JUN(L,
and4or7    , 0047, L)JUN(L,
and5       , 0050, L)JUN(L,
and5or     , 0051, L)JUN(L,
and5or2    , 0052, L)JUN(L,
and5or3    , 0053, L)JUN(L,
and5or4    , 0054, L)JUN(L,
and5or5    , 0055, L)JUN(L,
and5or6    , 0056, L)JUN(L,
and5or7    , 0057, L)JUN(L,
and6       , 0060, L)JUN(L,
and6or     , 0061, L)JUN(L,
and6or2    , 0062, L)JUN(L,
and6or3    , 0063, L)JUN(L,
and6or4    , 0064, L)JUN(L,
and6or5    , 0065, L)JUN(L,
and6or6    , 0066, L)JUN(L,
and6or7    , 0067, L)JUN(L,
and7       , 0070, L)JUN(L,
and7or     , 0071, L)JUN(L,
and7or2    , 0072, L)JUN(L,
and7or3    , 0073, L)JUN(L,
and7or4    , 0074, L)JUN(L,
and7or5    , 0075, L)JUN(L,
and7or6    , 0076, L)JUN(L,
and7or7    , 0077, L)JUN(L,
andor      , 0011, L)JUN(L,
andor2     , 0012, L)JUN(L,
andor3     , 0013, L)JUN(L,
andor4     , 0014, L)JUN(L,
andor5     , 0015, L)JUN(L,
andor6     , 0016, L)JUN(L,
andor7     , 0017, L)JUN(L,
not        , 0100, L)JUN(L,
not2       , 0200, L)JUN(L,
not2and    , 0210, L)JUN(L,
not2and2   , 0220, L)JUN(L,
not2and2or , 0221, L)JUN(L,
not2and2or2, 0222, L)JUN(L,
not2and2or3, 0223, L)JUN(L,
not2and2or4, 0224, L)JUN(L,
not2and2or5, 0225, L)JUN(L,
not2and2or6, 0226, L)JUN(L,
not2and2or7, 0227, L)JUN(L,
not2and3   , 0230, L)JUN(L,
not2and3or , 0231, L)JUN(L,
not2and3or2, 0232, L)JUN(L,
not2and3or3, 0233, L)JUN(L,
not2and3or4, 0234, L)JUN(L,
not2and3or5, 0235, L)JUN(L,
not2and3or6, 0236, L)JUN(L,
not2and3or7, 0237, L)JUN(L,
not2and4   , 0240, L)JUN(L,
not2and4or , 0241, L)JUN(L,
not2and4or2, 0242, L)JUN(L,
not2and4or3, 0243, L)JUN(L,
not2and4or4, 0244, L)JUN(L,
not2and4or5, 0245, L)JUN(L,
not2and4or6, 0246, L)JUN(L,
not2and4or7, 0247, L)JUN(L,
not2and5   , 0250, L)JUN(L,
not2and5or , 0251, L)JUN(L,
not2and5or2, 0252, L)JUN(L,
not2and5or3, 0253, L)JUN(L,
not2and5or4, 0254, L)JUN(L,
not2and5or5, 0255, L)JUN(L,
not2and5or6, 0256, L)JUN(L,
not2and5or7, 0257, L)JUN(L,
not2and6   , 0260, L)JUN(L,
not2and6or , 0261, L)JUN(L,
not2and6or2, 0262, L)JUN(L,
not2and6or3, 0263, L)JUN(L,
not2and6or4, 0264, L)JUN(L,
not2and6or5, 0265, L)JUN(L,
not2and6or6, 0266, L)JUN(L,
not2and6or7, 0267, L)JUN(L,
not2and7   , 0270, L)JUN(L,
not2and7or , 0271, L)JUN(L,
not2and7or2, 0272, L)JUN(L,
not2and7or3, 0273, L)JUN(L,
not2and7or4, 0274, L)JUN(L,
not2and7or5, 0275, L)JUN(L,
not2and7or6, 0276, L)JUN(L,
not2and7or7, 0277, L)JUN(L,
not2andor  , 0211, L)JUN(L,
not2andor2 , 0212, L)JUN(L,
not2andor3 , 0213, L)JUN(L,
not2andor4 , 0214, L)JUN(L,
not2andor5 , 0215, L)JUN(L,
not2andor6 , 0216, L)JUN(L,
not2andor7 , 0217, L)JUN(L,
not2or     , 0201, L)JUN(L,
not2or2    , 0202, L)JUN(L,
not2or3    , 0203, L)JUN(L,
not2or4    , 0204, L)JUN(L,
not2or5    , 0205, L)JUN(L,
not2or6    , 0206, L)JUN(L,
not2or7    , 0207, L)JUN(L,
not3       , 0300, L)JUN(L,
not3and    , 0310, L)JUN(L,
not3and2   , 0320, L)JUN(L,
not3and2or , 0321, L)JUN(L,
not3and2or2, 0322, L)JUN(L,
not3and2or3, 0323, L)JUN(L,
not3and2or4, 0324, L)JUN(L,
not3and2or5, 0325, L)JUN(L,
not3and2or6, 0326, L)JUN(L,
not3and2or7, 0327, L)JUN(L,
not3and3   , 0330, L)JUN(L,
not3and3or , 0331, L)JUN(L,
not3and3or2, 0332, L)JUN(L,
not3and3or3, 0333, L)JUN(L,
not3and3or4, 0334, L)JUN(L,
not3and3or5, 0335, L)JUN(L,
not3and3or6, 0336, L)JUN(L,
not3and3or7, 0337, L)JUN(L,
not3and4   , 0340, L)JUN(L,
not3and4or , 0341, L)JUN(L,
not3and4or2, 0342, L)JUN(L,
not3and4or3, 0343, L)JUN(L,
not3and4or4, 0344, L)JUN(L,
not3and4or5, 0345, L)JUN(L,
not3and4or6, 0346, L)JUN(L,
not3and4or7, 0347, L)JUN(L,
not3and5   , 0350, L)JUN(L,
not3and5or , 0351, L)JUN(L,
not3and5or2, 0352, L)JUN(L,
not3and5or3, 0353, L)JUN(L,
not3and5or4, 0354, L)JUN(L,
not3and5or5, 0355, L)JUN(L,
not3and5or6, 0356, L)JUN(L,
not3and5or7, 0357, L)JUN(L,
not3and6   , 0360, L)JUN(L,
not3and6or , 0361, L)JUN(L,
not3and6or2, 0362, L)JUN(L,
not3and6or3, 0363, L)JUN(L,
not3and6or4, 0364, L)JUN(L,
not3and6or5, 0365, L)JUN(L,
not3and6or6, 0366, L)JUN(L,
not3and6or7, 0367, L)JUN(L,
not3and7   , 0370, L)JUN(L,
not3and7or , 0371, L)JUN(L,
not3and7or2, 0372, L)JUN(L,
not3and7or3, 0373, L)JUN(L,
not3and7or4, 0374, L)JUN(L,
not3and7or5, 0375, L)JUN(L,
not3and7or6, 0376, L)JUN(L,
not3and7or7, 0377, L)JUN(L,
not3andor  , 0311, L)JUN(L,
not3andor2 , 0312, L)JUN(L,
not3andor3 , 0313, L)JUN(L,
not3andor4 , 0314, L)JUN(L,
not3andor5 , 0315, L)JUN(L,
not3andor6 , 0316, L)JUN(L,
not3andor7 , 0317, L)JUN(L,
not3or     , 0301, L)JUN(L,
not3or2    , 0302, L)JUN(L,
not3or3    , 0303, L)JUN(L,
not3or4    , 0304, L)JUN(L,
not3or5    , 0305, L)JUN(L,
not3or6    , 0306, L)JUN(L,
not3or7    , 0307, L)JUN(L,
not4       , 0400, L)JUN(L,
not4and    , 0410, L)JUN(L,
not4and2   , 0420, L)JUN(L,
not4and2or , 0421, L)JUN(L,
not4and2or2, 0422, L)JUN(L,
not4and2or3, 0423, L)JUN(L,
not4and2or4, 0424, L)JUN(L,
not4and2or5, 0425, L)JUN(L,
not4and2or6, 0426, L)JUN(L,
not4and2or7, 0427, L)JUN(L,
not4and3   , 0430, L)JUN(L,
not4and3or , 0431, L)JUN(L,
not4and3or2, 0432, L)JUN(L,
not4and3or3, 0433, L)JUN(L,
not4and3or4, 0434, L)JUN(L,
not4and3or5, 0435, L)JUN(L,
not4and3or6, 0436, L)JUN(L,
not4and3or7, 0437, L)JUN(L,
not4and4   , 0440, L)JUN(L,
not4and4or , 0441, L)JUN(L,
not4and4or2, 0442, L)JUN(L,
not4and4or3, 0443, L)JUN(L,
not4and4or4, 0444, L)JUN(L,
not4and4or5, 0445, L)JUN(L,
not4and4or6, 0446, L)JUN(L,
not4and4or7, 0447, L)JUN(L,
not4and5   , 0450, L)JUN(L,
not4and5or , 0451, L)JUN(L,
not4and5or2, 0452, L)JUN(L,
not4and5or3, 0453, L)JUN(L,
not4and5or4, 0454, L)JUN(L,
not4and5or5, 0455, L)JUN(L,
not4and5or6, 0456, L)JUN(L,
not4and5or7, 0457, L)JUN(L,
not4and6   , 0460, L)JUN(L,
not4and6or , 0461, L)JUN(L,
not4and6or2, 0462, L)JUN(L,
not4and6or3, 0463, L)JUN(L,
not4and6or4, 0464, L)JUN(L,
not4and6or5, 0465, L)JUN(L,
not4and6or6, 0466, L)JUN(L,
not4and6or7, 0467, L)JUN(L,
not4and7   , 0470, L)JUN(L,
not4and7or , 0471, L)JUN(L,
not4and7or2, 0472, L)JUN(L,
not4and7or3, 0473, L)JUN(L,
not4and7or4, 0474, L)JUN(L,
not4and7or5, 0475, L)JUN(L,
not4and7or6, 0476, L)JUN(L,
not4and7or7, 0477, L)JUN(L,
not4andor  , 0411, L)JUN(L,
not4andor2 , 0412, L)JUN(L,
not4andor3 , 0413, L)JUN(L,
not4andor4 , 0414, L)JUN(L,
not4andor5 , 0415, L)JUN(L,
not4andor6 , 0416, L)JUN(L,
not4andor7 , 0417, L)JUN(L,
not4or     , 0401, L)JUN(L,
not4or2    , 0402, L)JUN(L,
not4or3    , 0403, L)JUN(L,
not4or4    , 0404, L)JUN(L,
not4or5    , 0405, L)JUN(L,
not4or6    , 0406, L)JUN(L,
not4or7    , 0407, L)JUN(L,
not5       , 0500, L)JUN(L,
not5and    , 0510, L)JUN(L,
not5and2   , 0520, L)JUN(L,
not5and2or , 0521, L)JUN(L,
not5and2or2, 0522, L)JUN(L,
not5and2or3, 0523, L)JUN(L,
not5and2or4, 0524, L)JUN(L,
not5and2or5, 0525, L)JUN(L,
not5and2or6, 0526, L)JUN(L,
not5and2or7, 0527, L)JUN(L,
not5and3   , 0530, L)JUN(L,
not5and3or , 0531, L)JUN(L,
not5and3or2, 0532, L)JUN(L,
not5and3or3, 0533, L)JUN(L,
not5and3or4, 0534, L)JUN(L,
not5and3or5, 0535, L)JUN(L,
not5and3or6, 0536, L)JUN(L,
not5and3or7, 0537, L)JUN(L,
not5and4   , 0540, L)JUN(L,
not5and4or , 0541, L)JUN(L,
not5and4or2, 0542, L)JUN(L,
not5and4or3, 0543, L)JUN(L,
not5and4or4, 0544, L)JUN(L,
not5and4or5, 0545, L)JUN(L,
not5and4or6, 0546, L)JUN(L,
not5and4or7, 0547, L)JUN(L,
not5and5   , 0550, L)JUN(L,
not5and5or , 0551, L)JUN(L,
not5and5or2, 0552, L)JUN(L,
not5and5or3, 0553, L)JUN(L,
not5and5or4, 0554, L)JUN(L,
not5and5or5, 0555, L)JUN(L,
not5and5or6, 0556, L)JUN(L,
not5and5or7, 0557, L)JUN(L,
not5and6   , 0560, L)JUN(L,
not5and6or , 0561, L)JUN(L,
not5and6or2, 0562, L)JUN(L,
not5and6or3, 0563, L)JUN(L,
not5and6or4, 0564, L)JUN(L,
not5and6or5, 0565, L)JUN(L,
not5and6or6, 0566, L)JUN(L,
not5and6or7, 0567, L)JUN(L,
not5and7   , 0570, L)JUN(L,
not5and7or , 0571, L)JUN(L,
not5and7or2, 0572, L)JUN(L,
not5and7or3, 0573, L)JUN(L,
not5and7or4, 0574, L)JUN(L,
not5and7or5, 0575, L)JUN(L,
not5and7or6, 0576, L)JUN(L,
not5and7or7, 0577, L)JUN(L,
not5andor  , 0511, L)JUN(L,
not5andor2 , 0512, L)JUN(L,
not5andor3 , 0513, L)JUN(L,
not5andor4 , 0514, L)JUN(L,
not5andor5 , 0515, L)JUN(L,
not5andor6 , 0516, L)JUN(L,
not5andor7 , 0517, L)JUN(L,
not5or     , 0501, L)JUN(L,
not5or2    , 0502, L)JUN(L,
not5or3    , 0503, L)JUN(L,
not5or4    , 0504, L)JUN(L,
not5or5    , 0505, L)JUN(L,
not5or6    , 0506, L)JUN(L,
not5or7    , 0507, L)JUN(L,
not6       , 0600, L)JUN(L,
not6and    , 0610, L)JUN(L,
not6and2   , 0620, L)JUN(L,
not6and2or , 0621, L)JUN(L,
not6and2or2, 0622, L)JUN(L,
not6and2or3, 0623, L)JUN(L,
not6and2or4, 0624, L)JUN(L,
not6and2or5, 0625, L)JUN(L,
not6and2or6, 0626, L)JUN(L,
not6and2or7, 0627, L)JUN(L,
not6and3   , 0630, L)JUN(L,
not6and3or , 0631, L)JUN(L,
not6and3or2, 0632, L)JUN(L,
not6and3or3, 0633, L)JUN(L,
not6and3or4, 0634, L)JUN(L,
not6and3or5, 0635, L)JUN(L,
not6and3or6, 0636, L)JUN(L,
not6and3or7, 0637, L)JUN(L,
not6and4   , 0640, L)JUN(L,
not6and4or , 0641, L)JUN(L,
not6and4or2, 0642, L)JUN(L,
not6and4or3, 0643, L)JUN(L,
not6and4or4, 0644, L)JUN(L,
not6and4or5, 0645, L)JUN(L,
not6and4or6, 0646, L)JUN(L,
not6and4or7, 0647, L)JUN(L,
not6and5   , 0650, L)JUN(L,
not6and5or , 0651, L)JUN(L,
not6and5or2, 0652, L)JUN(L,
not6and5or3, 0653, L)JUN(L,
not6and5or4, 0654, L)JUN(L,
not6and5or5, 0655, L)JUN(L,
not6and5or6, 0656, L)JUN(L,
not6and5or7, 0657, L)JUN(L,
not6and6   , 0660, L)JUN(L,
not6and6or , 0661, L)JUN(L,
not6and6or2, 0662, L)JUN(L,
not6and6or3, 0663, L)JUN(L,
not6and6or4, 0664, L)JUN(L,
not6and6or5, 0665, L)JUN(L,
not6and6or6, 0666, L)JUN(L,
not6and6or7, 0667, L)JUN(L,
not6and7   , 0670, L)JUN(L,
not6and7or , 0671, L)JUN(L,
not6and7or2, 0672, L)JUN(L,
not6and7or3, 0673, L)JUN(L,
not6and7or4, 0674, L)JUN(L,
not6and7or5, 0675, L)JUN(L,
not6and7or6, 0676, L)JUN(L,
not6and7or7, 0677, L)JUN(L,
not6andor  , 0611, L)JUN(L,
not6andor2 , 0612, L)JUN(L,
not6andor3 , 0613, L)JUN(L,
not6andor4 , 0614, L)JUN(L,
not6andor5 , 0615, L)JUN(L,
not6andor6 , 0616, L)JUN(L,
not6andor7 , 0617, L)JUN(L,
not6or     , 0601, L)JUN(L,
not6or2    , 0602, L)JUN(L,
not6or3    , 0603, L)JUN(L,
not6or4    , 0604, L)JUN(L,
not6or5    , 0605, L)JUN(L,
not6or6    , 0606, L)JUN(L,
not6or7    , 0607, L)JUN(L,
not7       , 0700, L)JUN(L,
not7and    , 0710, L)JUN(L,
not7and2   , 0720, L)JUN(L,
not7and2or , 0721, L)JUN(L,
not7and2or2, 0722, L)JUN(L,
not7and2or3, 0723, L)JUN(L,
not7and2or4, 0724, L)JUN(L,
not7and2or5, 0725, L)JUN(L,
not7and2or6, 0726, L)JUN(L,
not7and2or7, 0727, L)JUN(L,
not7and3   , 0730, L)JUN(L,
not7and3or , 0731, L)JUN(L,
not7and3or2, 0732, L)JUN(L,
not7and3or3, 0733, L)JUN(L,
not7and3or4, 0734, L)JUN(L,
not7and3or5, 0735, L)JUN(L,
not7and3or6, 0736, L)JUN(L,
not7and3or7, 0737, L)JUN(L,
not7and4   , 0740, L)JUN(L,
not7and4or , 0741, L)JUN(L,
not7and4or2, 0742, L)JUN(L,
not7and4or3, 0743, L)JUN(L,
not7and4or4, 0744, L)JUN(L,
not7and4or5, 0745, L)JUN(L,
not7and4or6, 0746, L)JUN(L,
not7and4or7, 0747, L)JUN(L,
not7and5   , 0750, L)JUN(L,
not7and5or , 0751, L)JUN(L,
not7and5or2, 0752, L)JUN(L,
not7and5or3, 0753, L)JUN(L,
not7and5or4, 0754, L)JUN(L,
not7and5or5, 0755, L)JUN(L,
not7and5or6, 0756, L)JUN(L,
not7and5or7, 0757, L)JUN(L,
not7and6   , 0760, L)JUN(L,
not7and6or , 0761, L)JUN(L,
not7and6or2, 0762, L)JUN(L,
not7and6or3, 0763, L)JUN(L,
not7and6or4, 0764, L)JUN(L,
not7and6or5, 0765, L)JUN(L,
not7and6or6, 0766, L)JUN(L,
not7and6or7, 0767, L)JUN(L,
not7and7   , 0770, L)JUN(L,
not7and7or , 0771, L)JUN(L,
not7and7or2, 0772, L)JUN(L,
not7and7or3, 0773, L)JUN(L,
not7and7or4, 0774, L)JUN(L,
not7and7or5, 0775, L)JUN(L,
not7and7or6, 0776, L)JUN(L,
not7and7or7, 0777, L)JUN(L,
not7andor  , 0711, L)JUN(L,
not7andor2 , 0712, L)JUN(L,
not7andor3 , 0713, L)JUN(L,
not7andor4 , 0714, L)JUN(L,
not7andor5 , 0715, L)JUN(L,
not7andor6 , 0716, L)JUN(L,
not7andor7 , 0717, L)JUN(L,
not7or     , 0701, L)JUN(L,
not7or2    , 0702, L)JUN(L,
not7or3    , 0703, L)JUN(L,
not7or4    , 0704, L)JUN(L,
not7or5    , 0705, L)JUN(L,
not7or6    , 0706, L)JUN(L,
not7or7    , 0707, L)JUN(L,
notand     , 0110, L)JUN(L,
notand2    , 0120, L)JUN(L,
notand2or  , 0121, L)JUN(L,
notand2or2 , 0122, L)JUN(L,
notand2or3 , 0123, L)JUN(L,
notand2or4 , 0124, L)JUN(L,
notand2or5 , 0125, L)JUN(L,
notand2or6 , 0126, L)JUN(L,
notand2or7 , 0127, L)JUN(L,
notand3    , 0130, L)JUN(L,
notand3or  , 0131, L)JUN(L,
notand3or2 , 0132, L)JUN(L,
notand3or3 , 0133, L)JUN(L,
notand3or4 , 0134, L)JUN(L,
notand3or5 , 0135, L)JUN(L,
notand3or6 , 0136, L)JUN(L,
notand3or7 , 0137, L)JUN(L,
notand4    , 0140, L)JUN(L,
notand4or  , 0141, L)JUN(L,
notand4or2 , 0142, L)JUN(L,
notand4or3 , 0143, L)JUN(L,
notand4or4 , 0144, L)JUN(L,
notand4or5 , 0145, L)JUN(L,
notand4or6 , 0146, L)JUN(L,
notand4or7 , 0147, L)JUN(L,
notand5    , 0150, L)JUN(L,
notand5or  , 0151, L)JUN(L,
notand5or2 , 0152, L)JUN(L,
notand5or3 , 0153, L)JUN(L,
notand5or4 , 0154, L)JUN(L,
notand5or5 , 0155, L)JUN(L,
notand5or6 , 0156, L)JUN(L,
notand5or7 , 0157, L)JUN(L,
notand6    , 0160, L)JUN(L,
notand6or  , 0161, L)JUN(L,
notand6or2 , 0162, L)JUN(L,
notand6or3 , 0163, L)JUN(L,
notand6or4 , 0164, L)JUN(L,
notand6or5 , 0165, L)JUN(L,
notand6or6 , 0166, L)JUN(L,
notand6or7 , 0167, L)JUN(L,
notand7    , 0170, L)JUN(L,
notand7or  , 0171, L)JUN(L,
notand7or2 , 0172, L)JUN(L,
notand7or3 , 0173, L)JUN(L,
notand7or4 , 0174, L)JUN(L,
notand7or5 , 0175, L)JUN(L,
notand7or6 , 0176, L)JUN(L,
notand7or7 , 0177, L)JUN(L,
notandor   , 0111, L)JUN(L,
notandor2  , 0112, L)JUN(L,
notandor3  , 0113, L)JUN(L,
notandor4  , 0114, L)JUN(L,
notandor5  , 0115, L)JUN(L,
notandor6  , 0116, L)JUN(L,
notandor7  , 0117, L)JUN(L,
notor      , 0101, L)JUN(L,
notor2     , 0102, L)JUN(L,
notor3     , 0103, L)JUN(L,
notor4     , 0104, L)JUN(L,
notor5     , 0105, L)JUN(L,
notor6     , 0106, L)JUN(L,
notor7     , 0107, L)JUN(L,
or         , 0001, L)JUN(L,
or2        , 0002, L)JUN(L,
or3        , 0003, L)JUN(L,
or4        , 0004, L)JUN(L,
or5        , 0005, L)JUN(L,
or6        , 0006, L)JUN(L,
or7        , 0007, L)EB(L)

#include "gorgodandgot.h"
#include "oars.h"

typedef void (*fun_t)();
static fun_t mc21_lookup[22];
static N(dot) {O;}
static void ada_not_mc(OARS, void **t, void **s, Q_t wc) {
  mc21_lookup[wc](ο, α, ρ, dot, t, s);
};
static void ada_and_mc(OARS, void **t, void **s, Q_t wc) {
  mc21_lookup[wc](ο, α, ρ, dot, t, s);
};
static void ada_oor_mc(OARS, void **t, void **s, Q_t wc) {
  mc21_lookup[wc](ο, α, ρ, dot, t, s);
};
static fun_t ada_not_jun[2];
static fun_t ada_and_jun[2];
static fun_t ada_oor_jun[2];

N(init) {
  ada_not_jun[0] = got, ada_not_jun[1] = ada_not_mc;
  ada_and_jun[0] = god, ada_and_jun[1] = ada_and_mc;
  ada_oor_jun[0] = gor, ada_oor_jun[1] = ada_oor_mc;
  A2(mc21_lookup, init_mc21) O;
}

N(ada_not) {
  ρ += 3;
  Q_t oc = ο[ρ++].Q, ac = ο[ρ++].Q, nc = ο[ρ++].Q;
  void **t = &ο[α].v, **s = &ο[ρ].v;
  α += nc, ρ += nc + ac + oc;
  ada_not_jun[nc != 0](ο, α, ρ, t, s, nc);
}
N(ada_and) {
  ρ += 3;
  Q_t oc = ο[ρ++].Q, ac = ο[ρ++].Q, nc = ο[ρ++].Q;
  ρ += nc;
  void **t = &ο[α].v, **s = &ο[ρ].v;
  α += ac, ρ += ac + oc;
  ada_and_jun[ac != 0](ο, α, ρ, t, s, ac);
}
N(ada_oor) {
  ρ += 3;
  Q_t oc = ο[ρ++].Q, ac = ο[ρ++].Q, nc = ο[ρ++].Q;
  ρ += nc + ac;
  void **t = &ο[α].v, **s = &ο[ρ].v;
  α += oc, ρ += oc;
  ada_oor_jun[oc != 0](ο, α, ρ, t, s, oc);
}
N(ada) {
  Q_t j = ο[--α].Q, nc = ((j & 0700) >> 6), ac = ((j & 0070) >> 3), oc = ((j & 0007) >> 0), tc = nc + ac + oc;
  void **t = &ο[ρ -= tc].v, **s = &ο[α -= tc].v;
  ο[--ρ].Q = nc, ο[--ρ].Q = ac, ο[--ρ].Q = oc, ο[--ρ].c = ada_not, ο[--ρ].c = ada_and, ο[--ρ].c = ada_oor, mc21_lookup[tc](ο, α, ρ, dot, t, s);
}
