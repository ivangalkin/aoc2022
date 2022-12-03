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

static std::vector<std::string> input = {"vJrrdQlGBQWPTBTF",
                                         "fcpTMnMqMfTnZpgMfPbFBWzHPpBPzbCPPH",
                                         "mcVMfcsqZgmgVcmfgcmZmqZNJhrlrdhNhDdrRRJSvDTRhJlD",
                                         "pMFRmLwHMbRPmMbPPddvqqrrNSTFVttdrN",
                                         "hgfpgCGZcjpcgfvNtdrtjvrdtSrd",
                                         "gZgsBBBlZggBGhsfhpzlzLDLmLRDRMLDPw",
                                         "hChhMFCvqtTMwbSSHgTZWHZd",
                                         "jjBNPjJJNfsNjVnVJJNcNfPwGbSbDZnZZgHrddwHrrgWGb",
                                         "mBBRRmBBQBmNJWhCzqllzhRCCv",
                                         "lQgpngNgQvHdSgWwjMRmDjmMDHmm",
                                         "zCLVzfzzbbCzsZZPbZPLfFJJMDWWRcDsmJRcjmwTmlRj",
                                         "BblftzBtlFznptSQQQppNG",
                                         "wJJwqCtCGRcVlqlM",
                                         "BQpppjBQLczTrvHRjH",
                                         "QQQFnmQWWRfnpQBpQpfDCwCdbPDCwbNNPtdJPCZw",
                                         "gpJjshBpgjZGppJqBGJjJZzTwzTmcvzwwcmvwsCFdmcF",
                                         "WPSSWWSQLVdDDfWltDWLPfttvFCVmzCCTFnmwcnnnCTCzVVv",
                                         "tLldLltDQfflrRWNqBRjgHBpJNZjHj",
                                         "bzVJjVnjbCGVLZQLmmsJZZQQ",
                                         "RrwwzhPScWSwrhvZZvZlZvvSTsQS",
                                         "HwFhzFWdPHfcPwPWPdhWffnngpjtnjgtpnfGCGnG",
                                         "CPwQtftDQfPDBPBCfDDDCDptszcpVVddcRczVLVdccRGrLWs",
                                         "FqlSnhlqhmhMbHqqSQlHbcrRrsWzRdzdWVzLRGRrVF",
                                         "MbQmSnHZhqZMQMTJCttjCgPCwfgDwT",
                                         "CCSpvHtZHSwftFtdtbfR",
                                         "QJmNPmjjJNgNVNSzDlmRqbWlqWWfcqfWqbwfqR",
                                         "MDhJzmSMDmsZrLhssrvh",
                                         "ZhznnrLzcHhHSjsjSBSsBnSS",
                                         "dTwqDdqDRQjNdwqjldggDvBJfmBfTSBbBSvfSJsmff",
                                         "DjCldNglVwFVgZHHHzhCMcLhMC",
                                         "vBnShjwwSshmQPmtJLpJtn",
                                         "rDLFCWrClWCMWWVrbFVJqpQqpHmtbzJPQzJmzb",
                                         "ZMCCDCMNrTWTrgScgGRhsvcsGLSG",
                                         "LQpJglQQRjQsppfsQbjfbQlBgBhFhrvghhZCdPZZZthPgv",
                                         "zVHDMSWVVMVWDzmnVMHDSMMzZvNFFrFvPCdmdFdNdrBPZhhd",
                                         "ncqqSzMVCcGWVSCTWCDcVTffLLLbJsLLsRLblRQTps",
                                         "zjGzLQtFzzRgwwLhVrqw",
                                         "dfClCdHZsmffZDWlBZHCDBmhJbqTgbwgqbTnwrgrqRbT",
                                         "HsdwPCsWDpDsBpfdWdHldWpsGvvccPvGcvzQvFQvccjNztQt",
                                         "wmVVgFPrFdwJrlNHQHSHCCHL",
                                         "tWBtvnBqZZMpcvmmqMBRCQQLCLWCHfNQQCSGWL",
                                         "BBsnmcpqPswFsTws",
                                         "BQRpFPJJJJPmPRqZNFVhcczHHzggwjBhghgzHw",
                                         "snTsTLtrlvSSSslsGdcwmjhgggvjHhmH",
                                         "nSsWWTtCbbDSnlRRZCfFRNZmCVJf",
                                         "tRRMCWLtJWQLqLrmLHVLqmqh",
                                         "JszPjSbGbsnGnSZprVpFhvFqvhrqZZ",
                                         "zgbGSDBbPsTgbDBzzSDnDnPTcWlWJCQlNttNwwwMcMctcW",
                                         "hlVRvPvzqqtRdwRRJsst",
                                         "HHVNVBMBjHLTjVjwDjsbjJwbdmbbss",
                                         "NBZHMCNVCCpgLTWggBpgNLTvqCPnGhQhCCGlqlhfcvvGfn",
                                         "mwbfbfbDCqRJZRbCSvmfWTQFczTznnnFTFnrzJsz",
                                         "BdhHlLjpjjjncSprnsSFWS",
                                         "ljhVBPjSdHPRfZRZDvVRZM",
                                         "tGqbqBSsntRgNqwNNVVHVN",
                                         "hclFvJZvCDFppDpZpHNggMTwdlrMQNVgHM",
                                         "CCFmcZLDFpvzZhCFJvZvmwjSRWsBLWsnfWjRRGGfnsst",
                                         "GdGQQFdcMPwMdLFvWsNWFDLfss",
                                         "SqjhtjnrbVznSztSqtzpjztVvTmNNmmfMMfDDMDDNTqfgsqv",
                                         "rVhhZjppVrhpVzRbjSnzHPMwlJCJQdcRPPlPPcHJ",
                                         "JVQLVgVZghFtFlhghtvSzsddmrdvssmzSWtd",
                                         "HTMJCBMCjnwNBnCbTNwMdWfzvzsrsvffWbdsmfPr",
                                         "BGnnpDnTjjHJwDBNpqlFQVQFQclcRFQqpR",
                                         "BRhbrQDttbTTtRDtTRRzLHWZLZHGSqWLCBNWqLNL",
                                         "fwFPPSjmsmJGLsNH",
                                         "dvfSdvfVMjPTttTzczgTcd",
                                         "dZgggwzgvsggtdstZTZgdfnhSJSSJDDhnDBdppnGnhSp",
                                         "VQWRQWVCRLFGnThJCpFJ",
                                         "LbmmbQVcHcmmlWjmVlVQNVRzvwwZvTrsrNwNwzZrMvfsqt",
                                         "lDZQSlHDbLccRPQhCNhG",
                                         "gtsntgvdvBvvqgsTgBggdrWRNzPhWczPbWcdWCccGGGP",
                                         "sTBttvrFnnMTMJngbqfLlZLpwFVljwppZZDl",
                                         "zNNNgqpgmLgqlHBHsMGslH",
                                         "WdWFrFwhcwWRwhddcRWcdQbcDDslzBDszsHbGBDfbHfzVlVl",
                                         "ZvhRrvPQwvWFQRZvFdJttSPgCmNppCNzJnJS",
                                         "fCzRRNGfqNRvwpQhwrGcwZZT",
                                         "gJnStgMmLhdHndSSTjcTrTpcmrjjcrrw",
                                         "FFJBbdddFPPhFFNWCF",
                                         "btrHRSBBSNLLRPLwhbhpqpfWhQppWZ",
                                         "zCzTvvmgDvgDZhqWZZthtDZh",
                                         "ttTjMsvCgRRLRSsBRG",
                                         "LsSFFTTDWdCsmFTlLSsLDDRRQCvhpRQGNGQBJBhGGMNB",
                                         "zqPtqZnjPPrPvJHBMHrJrMpv",
                                         "VbqfjZfwgtfjPgZPgtwDLTLcTlcFdWLdcdVTJF",
                                         "pfMCDmpHbdMQQdQFFG",
                                         "gdjldRsVFRntQnqR",
                                         "rlJVsWgWPWjsslSpDbScmSDPHfCd",
                                         "lnFFGgBFBslDFGbFSjnNTjjppSrQHhnT",
                                         "zcvmCRcvZmcZzWpTQhQrrTSPtHWH",
                                         "CRccrZJmdJlwDJwgswGg",
                                         "hllrrDzggGppgSSLNWgW",
                                         "jlTlPwwqjjntVpWWPNnP",
                                         "wjjJqvQjJjQJbTjlFqhBMzfDDmMCGBMHDCGb",
                                         "jvQPhhtCRtfmqHHjqHHJsl",
                                         "FFSTcBTBTMwFGCTwMTcGwTVnsHSJzqqJJJplmlpJHszZZzZD",
                                         "dLMdVMNGBdGFMTNTRRLrQWCQhgWQbhgf",
                                         "gdRgdgzzrvrzggDwgDGpPLzrbNljMTsbWWjWjZbTjLZMWcWj",
                                         "tFfCQHJJnJMJTJjNNMjl",
                                         "HmtffVttqHQmBCBQCqfFnCwRqpDvPRrGppRggNzdwgzp",
                                         "DHSqzQbzWlRLDzMZNpVLgnpNLggw",
                                         "cZcdTmPPthPdsvvdhPGTvJgwnpgjjTgNNwMVngNBjNfn",
                                         "PPdJPvrtGtcFdFFchDRHDqHzZWSQQCrQWQ",
                                         "BcgnLBLsFvRnGRRRlzfJbbPJzwHPwPFz",
                                         "hCDjWMDVNfVllfzddw",
                                         "qqMqpWCMjDTWNWTBLpgsgLvZwtGLLg",
                                         "zczPgpGzhnbmbchhHwqwhSwfwHCFWw",
                                         "VJdmVLlLdVJSJWHSTFwH",
                                         "rlttQLVLdvvZpgcGbmDrzGMD",
                                         "WSvtpqqtqccttVQpVvJNJSVNCmTlnCWwTTnWlBBBjwCBTlTP",
                                         "ZgfPHfPfMHsDCwnlGBwTMGBM",
                                         "rgdffZhPrrLsdLZpvcFSJJNvpJhcJv",
                                         "qVdqJGvzgJzJgwzgWvdJzpblcRRWmLFFcLBmllFRRMRFRH",
                                         "TGGSsSssNPTSLlRLcPHMmnPB",
                                         "tTjTZtNGhrCjQNCjQQDTCSjZvfJbdgqrdpwqfVzwgzvdvVgb",
                                         "VTmwcTVSMHwbMwbDVBTcMpJfpfnWqdJbZpJldfsjZn",
                                         "hNtPhtzFzPQGCCGFFCGtnqQqWZWplsjWdlnlldJn",
                                         "vRCRzvvFFFvhrRthPtLrtNGSwBVDScDSgHHjwwcBgSgTSL",
                                         "dWCsWbWWchblsmbWVZqqsSpsGfBqBVBB",
                                         "DtTtjPJrgjjtTTwgPwwjrTgnLqSBZQLqngQppqnfBVQfGp",
                                         "PJPwwtDwHGGJtJRFHmhCFRCvdmHR",
                                         "mMsMJSCjllsSSmBBclsMsJHDbcHqqbHpqHGbDZHbqHpb",
                                         "RnQnGVnzGzFQgzWzpzvpqDHW",
                                         "QVhRTfGLLFGTTFFwhnQVNfFwJsJsMjsBMrlsjrJlPSPlTrls",
                                         "JNMJSVSGVCjnWZMZWWcH",
                                         "gLTcqbqhqbbgzgnjpnjjWHnP",
                                         "wqlbcrfTwrvcLBwwRtJwsNRstRsCCN",
                                         "MlBssQBchZDLNJZgmvGg",
                                         "fdzHMfHSzSprfgSvvJbmvDGNDW",
                                         "PCHTRfjHnzHMzzfrCPCpMTlFhcFstqVwVCFllQcBtqss",
                                         "TtFnnFJfDhtdfJJcFtfnsfcFjBjLDjHrDLrCjMjwCLLrZjrS",
                                         "qQmWmQzvWpRQGvgpGGRGRzmWwZMwBLCHMZjbBBCLwrHSLrqr",
                                         "MRllgRWWMlsJFnlFclJT",
                                         "SRRrRDRBRTdbdMRZBZMprTCJCnWGvChJGzLSWWzsGhCs",
                                         "wwqHPtFwjwTHLHvGTsGW",
                                         "FlPtqTNVcTVtwtmjRbBZfQbfZbQmRRMR",
                                         "WSWfQttffsHSfRRRStfnCsQQqlJpbhnrnmNzJbzqNbbrpmnb",
                                         "FGFPddBcBwDPzpzbWlpzDbbh",
                                         "ZPdPPLMFdGwFFGdwGdZwcZgTtSTVCsRRSgSRTQWTTtCTtH",
                                         "vHsfGHTvSvHHHsGHctMgtHrJwbJJwrjgbrdzjWCrdrrw",
                                         "hqZRLmmZpFhcLhFmrzJQbzzmQQJWJJbm",
                                         "LNZFcpPlhBRhqDDllRtnMssGfBsnttGTnttT",
                                         "VDVrLrZZcjrhhFrZppGlglGMPFwFWNQw",
                                         "bzszSBHBWNGcscpN",
                                         "TJqBqSfTBBqBHzJqddBqzcLnLjnhCRTvvRrnDrvrvZRn",
                                         "GLzrNWbtMptHDmNDglgmlD",
                                         "fZtcfCRvtBcQjdjgmmjj",
                                         "RhBhhqfSPPpttrnPnVVW",
                                         "BhVRJGwWqtHjZqTDLZ",
                                         "gQnfpBdPNpQrPNSfBdndnpTTDFZttDLLzZzTzCLNLZZD",
                                         "mQQPsgrldpgdBQgSbGVcmcRwGMWhwVwW",
                                         "DrLCctBCLQtSSQcLbcQHWvvvlWHHnWlWBlNRRB",
                                         "wqdmpgqsZhzGphwwpZGsppRvfnJsWfHWvfFfWFsfvlNN",
                                         "mwmhVppTqpGqpNZpqTbSLLttDrDDtPQTtr",
                                         "qwqmgnglDnlgtQzQJzJQhmWQ",
                                         "pTpTpssdsVvNsdTSZGdSdjvCRcqcRcVWVczhWChtchzWcR",
                                         "sGTvPqZvSGdZZGdsvNGdPHrFHFBDlDLwPgBFLLBB",
                                         "BBBGsGGBrBBrqWVqRnWBBBWpzFwMhjMFSFPzzSwPFPpzzFvg",
                                         "HtCdDdDctZDtbHCffcbddbNfvjvFSPFjMhMgLwPgjbFhjFFj",
                                         "NJTDdltNgCNDZJJZCDJZDfJtrWWnQGBqlRVVlrBsnlrqqmnr",
                                         "PwZhgbZSWSqqGznv",
                                         "tTPVVmptcsrNrsTNpjRzqfHvvGfGWjfjqGzHWn",
                                         "RVRtVDRmsRtrctmJDtgBBhBhbFgJPFFMFJgP",
                                         "jPzzCCPzTtTfzrRtgSNVRHvFQVvbpQppVN",
                                         "sSnDlBGBwJbFNplVlN",
                                         "cLwSwdMhSwcBcsBZgWjCTCWfCLffrg",
                                         "RSNPvTTNqFTSvNrSBvBGJGzmFMslgCMJCgmzlc",
                                         "fDVfpptLWQfnVLffVHbQDQCclJzGGCtGmmGJmzMshzGh",
                                         "VfQnWZfZDbdnVHWcfWnfHWVvPrTSNZqSwSqPjjvBwRqrNS",
                                         "FLRpmRwcpjfzjSnD",
                                         "tGvPNvBnPQggPQQvPgNHDjSSjDzzthjzfHrjlT",
                                         "JGqvWNCCGQBWGBQvVLsCMMRLRnRMnwMc",
                                         "fGJbzgBffCGpPGDVnG",
                                         "mcTccshvbbdRNRsNjdLjnVlHVnHLqVpDpDqD",
                                         "wdmsWvWssbZTcWvRhfzMQtrzMgrfrZJgfQ",
                                         "NfSbvZHZNRSbQbbQgZrMjhLwMrjLjwHLCmmh",
                                         "NTWdJBFcWJFcdsFJqcqPwqmjpMrLCMpLMwLP",
                                         "dNJctnFBVfSGgvnfZz",
                                         "GSnRJfGfRJgMDMGWnfzdmptpFJppLvwLwvLt",
                                         "hbjZzrQbblqcLtpwlHvFplTH",
                                         "qrzqbschrQCqqjPcCVcCGDfGMWDgWNGDDSfgnf",
                                         "vmMpCdTndCvMdmnFcCRJWBJGcZJRJB",
                                         "NDNwGzshPLrwVVNsjswhGzjFSfFFQQRSJWRBFcFRfsWFQB",
                                         "NwNhNjVzhhzzrgzdqqvqtnqvlqdggG",
                                         "MdPLVSSlMMVMmlLBBLFdvZNWqWztStttRRNqzqNGTq",
                                         "DhJfhghhCgwChJgJwHHzbsHpnZRtTWqqfZRGTnWTZtNqNRWR",
                                         "hwHpJbprwpQhDHDCbCCzsClBvrLMVFPvmPlMMVMdLrvj",
                                         "DssDrqRsWsNfzfsWLRzjgTdBlgzFpMlgTFTglT",
                                         "ttCZnSQmSQmgjGQGQgDlBp",
                                         "bhDnCmbwVmCwwtZttPwbRWsRJcqWJfcfsfrqVrqq",
                                         "ldBgTMTRvBDVnCCCTdSRTqNjbjSbPPPPqtfPqtPJFJ",
                                         "cZHZrszLrrrZHrbNjNtbJCfqNJLt",
                                         "GZzCzWZGGsGzmzZcmGssZzZVvnVdBDddRRDnVlWgRTDdBM",
                                         "RjNrrjwGDDqqGJsHtzpMHHGz",
                                         "QCbWgbShmBCCPClmmWFHzJzTbDdsMJsTtpTD",
                                         "fffQfnSCWDBfhCDLRrNrwcrqVqwNqn",
                                         "zmRrDRzqjmLLHzDjLsHLflJlVVJlWWTDTfdMtlWJ",
                                         "pPQQnbvSpvNbgfgfVtMVJfgdtG",
                                         "SnpnVFcPnNnPvpNSFNSbhHLhrjhCqRsRBRrHCLhzmC",
                                         "CZZzlnCZNlGGcbVrbtVlMtct",
                                         "MgFQDFgQRLLHhJgDFqQJQLgdtVTrttSrPSmcbmTtvSqvVSTV",
                                         "hFQDDfMDfLgHwWfBzWwwsZGW",
                                         "bHVDdHVHTPMvnSQnWSDQgDmm",
                                         "GhrCJfbfrhfbRJcqGqlwZtnBRtBWSQgQWWnWQW",
                                         "lfcCrqJhlfFqphpplNCrNVMPMPLbsLPLzFVHVLsVdz",
                                         "VDhFCZhtFdPqwwcp",
                                         "SvnvHNNnTvbwNNgnHwTHgwBTLcdqmmfmqLGmmTRLPfpdGP",
                                         "BNWsHJgSnwgMMgMBBWMDVJjtjZrDJZzztJhjQr",
                                         "HDsSHLRnpjbpbbRDbqLjLjjGGVffMVGMdvnfMcNvfBBGcB",
                                         "TCzQQztwwNTMqMdBVv",
                                         "hCQWmtCzZthPPZPrLjSbJqjSjLLFjLpr",
                                         "ZrrZqJDcZSCFLLHBFcjjHF",
                                         "TgvnDTlTtQwgBfwwwzLjGLdF",
                                         "VbnVngMtvDTTVMQDQMDQlsbZJChCmCPhprrZqhqZSZPJ",
                                         "glMGHBJTJJTplgwcCgcqcFhhbWncFm",
                                         "sSswtPfRDmWcCqfchq",
                                         "RZSdSzsVzNPSwSSQsdzSSQpGLjJTMpBGrJrLLrplZBpG",
                                         "WQqqwLqQlnlWDwtbVbtCNfVbpV",
                                         "dFTRjBPhcBgBrFhTPhrbVptJpNNbbtJCbJSL",
                                         "hjcmcRmgPPcRcPDmHHzGLWmsDmzH",
                                         "rWFmrRmmccSZJWvSLZTH",
                                         "hDPhGbhSjtbpqJLvJHjLHTqj",
                                         "pnplBlfBPPhlgfDbDhglPMMrwrRRSSncwccQzddzmC",
                                         "LbccJCGzbcCJcfGczcnmNnvNmZNLSDZZWPWS",
                                         "dwstRhTsrsFddPZqvNWP",
                                         "BBggRrQstBwBRTHWTprRCHHGVljfCGCfcljHjbGV",
                                         "FHVBSVDvnsFDwwSVwwvGVSMFWhWcWptMWchWMtPPcWtNNWcj",
                                         "TgqJrJTRmRCNrbcLjprLnp",
                                         "qQTlfdlZQgmfqqnFVznvQwvnsBsV",
                                         "TGpDDMQGMZNtfvDJdtWd",
                                         "jbrmstmllRmNvVhmmvJVhv",
                                         "tbrRzFFLlRrjFlLlTQgLQwwLMwgTZBTB",
                                         "QFgFWQQfSgLFGmtnnVmqCPWmPH",
                                         "TTzjgTbRRqnRsCPCsP",
                                         "NDMMgZjzcJvbjhMcjZbbbJJNpdpBfBvSBBQwBSQLQSpSplBG",
                                         "zcRNsQSSMjRsNNZZFBLQHHFFBPWF",
                                         "tvwCtgvqLJNnNBCH",
                                         "fNNwqrqNMpTrDlcs",
                                         "MMHMVPRJHJWvqzWctbtQQdQz",
                                         "DFfNFffDnTllfTfFfmzsjqcdtQGQpbddQQbssn",
                                         "mlFNCgFNNNLrmLFCThhhzJBvhSJPVhMgMh",
                                         "PWjhljbHFhjbFMWhjbPfhbTGZvlGcGlCLvvwtGCNZGvc",
                                         "SRqBqBrmQWQrgQrrqrJBLZNccLNZmTCtvTGtCvCt",
                                         "rJDzDSSBrzdqQWDPHFMjMFdjHMVnbM",
                                         "qqLwvvtrLFqqfqrjjjdBZfBCBBJdlT",
                                         "ZGZpRZHbQDzDWRRRVdBzSSlBdzjjzdJJ",
                                         "ZGpgNDQmWGDRmRpZMQbvPPtnnFnLsstFmnFrPL",
                                         "TdhcfZhdZZdpdbPWttCWrrCN",
                                         "MBMMqRLgpGpFFWbNsvLwvCPCCP",
                                         "mpBMnBRMBGqJfZcfZZHZlhfm",
                                         "CdmGdnMcMwHjhDtFFnrj",
                                         "vPbVbPBPPpgpgWJpvTjqDZZqSHqVZShrDj",
                                         "BppjjgvbJjbpNbzPfNcGCLlCRcmLLflllGcc",
                                         "qDtgVttGFtlslStS",
                                         "gCZbbHCjvJbZjCbJhHhHJrZcslJcLzLllcLNFssMSsTlSM",
                                         "CWbWrZgWBQQBBpfdPm",
                                         "hstPtCGtltlTClllPJLScVdPdJjLPJMV",
                                         "NHRbDZDQSDFFjjdJ",
                                         "RqbQpgBmqZvqZNQqgZmmbszpTtthtCswhjslwwpTWC",
                                         "CVdwBJJdppbbwdBVrJbrJbGPlMFSLrjrPjmPFFmPRRDF",
                                         "NNWHHhNZTcQWhnNFlmSSlRmLjnPPRF",
                                         "qWsccHTZccsNsZcvTcNtStpBtbdVwpfBwbVCBq",
                                         "lPQHNJhMPMPFlNMHBqZBwQwQwQZwcCqw",
                                         "bWddDzbWbftdDSDbgttgnSDWccLwcvBczqcqGZzLccZTZwwc",
                                         "spWrssWrnDtDpfSWDtsFqlFPjNMjRJVVNNPJNp",
                                         "bCCfcWVLTHfSSdHwhH",
                                         "sGQSZSzQJmmQsphwHHHsndnpHN",
                                         "zPSqrmZPFCvFTbWMLV",
                                         "tLtVBGLJqGqVGbzGSCsSsSqQsFvZCSQv",
                                         "gRgdWlHTBHgjjHlWpWjWjrwdCfQRZFSssQQQZmQmMSvZfFMQ",
                                         "lPHlpWgjTldprNWHNNdHjTctcLbVcnNJJGbVzBhnbhhJ",
                                         "zVrSwzzJbVrbqFCVVVwVCztWDDtfTZsWDZTLZZmSWsDm",
                                         "bpgHlgBbbGGGglBGRNvMpWfTDjmDfWDjfRZZWLtmZs",
                                         "bGbvQHMpQccFJPPh",
                                         "VGqCPmPjfGqCdMqVMhjhmPChDJDJzvrrbrBvrdrpnJDpJDQr",
                                         "TSRsgHRSFHTlHvJvBDvvzlptbv",
                                         "ZFLTsRRgZTgWscHTfWNWNPPBfGqmmMfV",
                                         "TvTrrrCVCVwqjPrWfWhjfH",
                                         "RRmgmnggltRgNpzRsdfqWWjdFdvNHfdh",
                                         "zZlRzDGGZmbmmZbvGJVccwCMVcVVTLwDwC",
                                         "QPsNlvvvSccbbNQcSPvDVSvzTLLCgRVzCJgTJpgCpphgzh",
                                         "MDqHwFrMffgFpgpJLzTz",
                                         "ZtdrffBrdqmBBmfwMtDtQPPPbjcNvnllnlbNtScn",
                                         "HbbbcpTHHMMqNTCddCVBQvgPzJPJWQBQjvpBvQ",
                                         "FFrDGtntFFwhrRFDFthfRhRmSJPJvvJZjZjWJJvJQJnvWjjg",
                                         "rtfFfLmLRmNgdHqcLNHd",
                                         "FpFHCFWtFSnCWnBfJJfgMJDGHDGGsG",
                                         "rhrLrrhLrbtZThLfgsfGNDfgTgNcDs",
                                         "QmPjbdqjmbbbrmhQqQZrZStRdlnnFdlRzVVVWlnpzR",
                                         "bBMwwjzhbjhssvsGZBSZLr",
                                         "JFtnDtRzJtffJHWNtHncRRrvGZvSnllZZZsgvlnvVvlv",
                                         "RRPHPHFPHHdcHtzNfMQhdCwbqCmbMChhqq",
                                         "pWGdFSWwwjLdvgNNvggl",
                                         "mTNbmRPHmmVNmvZhnhBssBlhnb",
                                         "HPTzRPffJJNzjCFpDWDz",
                                         "MHlgzsqHlbmzgsHzlsbcRWPdPtjZFqhGGdrPrjPJGrVP",
                                         "vpwwvQwCnhNQpSnLdVtrrZGZtZjdVSdJ",
                                         "hfffwvTpvLwDpCLvDnQDHbmRRTcWRHMWWHWMmWMW",
                                         "WHlNHWWldjpwntnWBPpPQFZFBFhZBZCZ",
                                         "TqqvgvmgfmvDVLLfqqLsrFBRhrrBFJQBGPgPZGCR",
                                         "mcDbcDmzLcmDDzfVzTQNjNzNztdzjNdwSHlH",};

void _3_1() {
    int64_t prio = 0;
    for (const auto &item: input) {
        assert(item.length() % 2 == 0);
        std::set<char> first{item.begin(), item.begin() + item.length() / 2};
        std::set<char> second{item.begin() + item.length() / 2, item.end()};
        std::vector<int> v_intersection;

        std::set_intersection(first.begin(), first.end(),
                              second.begin(), second.end(),
                              std::back_inserter(v_intersection));

        for (auto common: v_intersection) {
            if (common >= 'a' && common <= 'z') {
                prio += (common - 'a') + 1;
            } else {
                prio += (common - 'A') + 27;
            }
        }

    }
    std::cout << prio << std::endl;
}

int _3_2() {
    int64_t prio = 0;

    for (int64_t i = 0; i < input.size(); i += 3) {
        char common = 0;
        for (char c: {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
                      't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
                      'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}) {
            bool found_letter = true;
            for (int64_t j = 0; j < 3; j++) {
                found_letter &= (input[i + j].find(c) != std::string::npos);
            }
            if (found_letter) {
                common = c;
                break;
            }
        }
        assert(common != 0);

        if (common >= 'a' && common <= 'z') {
            prio += (common - 'a') + 1;
        } else {
            prio += (common - 'A') + 27;
        }
    }

    std::cout << prio << std::endl;
    return 0;
}
