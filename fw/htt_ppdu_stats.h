/*
 * Copyright (c) 2017-2018 The Linux Foundation. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */
/**
 * @file htt_ppdu_stats.h
 *
 * @details the public header file of HTT STATS
 */
#ifndef __HTT_PPDU_STATS_H__
#define __HTT_PPDU_STATS_H__

#include <htt.h>
#include <htt_stats.h>

#define HTT_BA_64_BIT_MAP_SIZE_DWORDS 2
#define HTT_BA_256_BIT_MAP_SIZE_DWORDS 8
enum htt_ppdu_stats_tlv_tag {
    HTT_PPDU_STATS_COMMON_TLV,
    HTT_PPDU_STATS_USR_COMMON_TLV,
    HTT_PPDU_STATS_USR_RATE_TLV,
    HTT_PPDU_STATS_USR_MPDU_ENQ_BITMAP_64_TLV,
    HTT_PPDU_STATS_USR_MPDU_ENQ_BITMAP_256_TLV,
    HTT_PPDU_STATS_SCH_CMD_STATUS_TLV,
    HTT_PPDU_STATS_USR_COMPLTN_COMMON_TLV,
    HTT_PPDU_STATS_USR_COMPLTN_BA_BITMAP_64_TLV,
    HTT_PPDU_STATS_USR_COMPLTN_BA_BITMAP_256_TLV,
    HTT_PPDU_STATS_USR_COMPLTN_ACK_BA_STATUS_TLV,
    HTT_PPDU_STATS_USR_COMPLTN_FLUSH_TLV,
    HTT_PPDU_STATS_USR_COMMON_ARRAY_TLV,
    HTT_PPDU_STATS_INFO_TLV,
    HTT_PPDU_STATS_TX_MGMTCTRL_PAYLOAD_TLV,

    /* New TLV's are added above to this line */
    HTT_PPDU_STATS_MAX_TAG,
};
typedef enum htt_ppdu_stats_tlv_tag htt_ppdu_stats_tlv_tag_t;

#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_RATE_M     0x000000ff
#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_RATE_S              0

#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_RATE_GET(_var) \
    (((_var) & HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_RATE_M) >> \
    HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_RATE_S)

#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_RATE_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_RATE, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_RATE_S)); \
     } while (0)

#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_IS_AMPDU_M     0x00000100
#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_IS_AMPDU_S              8

#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_IS_AMPDU_GET(_var) \
    (((_var) & HTT_PPDU_STATS_ARRAY_ITEM_TLV_IS_AMPDU_M) >> \
    HTT_PPDU_STATS_ARRAY_ITEM_TLV_IS_AMPDU_S)

#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_IS_AMPDU_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_ARRAY_ITEM_TLV_IS_AMPDU, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_ARRAY_ITEM_TLV_IS_AMPDU_S)); \
     } while (0)

#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_BA_ACK_FAILED_M     0x00000600
#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_BA_ACK_FAILED_S              9

#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_BA_ACK_FAILED_GET(_var) \
    (((_var) & HTT_PPDU_STATS_ARRAY_ITEM_TLV_BA_ACK_FAILED_M) >> \
    HTT_PPDU_STATS_ARRAY_ITEM_TLV_BA_ACK_FAILED_S)

#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_BA_ACK_FAILED_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_ARRAY_ITEM_TLV_BA_ACK_FAILED, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_ARRAY_ITEM_TLV_BA_ACK_FAILED_S)); \
     } while (0)

#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_BW_M     0x00003800
#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_BW_S             11

#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_BW_GET(_var) \
    (((_var) & HTT_PPDU_STATS_ARRAY_ITEM_TLV_BW_M) >> \
    HTT_PPDU_STATS_ARRAY_ITEM_TLV_BW_S)

#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_BW_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_ARRAY_ITEM_TLV_BW, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_ARRAY_ITEM_TLV_BW_S)); \
     } while (0)

#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_SGI_M     0x00004000
#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_SGI_S             14

#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_SGI_GET(_var) \
    (((_var) & HTT_PPDU_STATS_ARRAY_ITEM_TLV_SGI_M) >> \
    HTT_PPDU_STATS_ARRAY_ITEM_TLV_SGI_S)

#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_SGI_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_ARRAY_ITEM_TLV_SGI, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_ARRAY_ITEM_TLV_SGI_S)); \
     } while (0)

#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_PEERID_M     0xffff0000
#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_PEERID_S             16

#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_PEERID_GET(_var) \
    (((_var) & HTT_PPDU_STATS_ARRAY_ITEM_TLV_PEERID_M) >> \
    HTT_PPDU_STATS_ARRAY_ITEM_TLV_PEERID_S)

#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_PEERID_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_ARRAY_ITEM_TLV_PEERID, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_ARRAY_ITEM_TLV_PEERID_S)); \
     } while (0)

#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_SUCC_MSDUS_M     0x0000ffff
#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_SUCC_MSDUS_S              0

#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_SUCC_MSDUS_GET(_var) \
    (((_var) & HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_SUCC_MSDUS_M) >> \
    HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_SUCC_MSDUS_S)

#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_SUCC_MSDUS_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_SUCC_MSDUS, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_SUCC_MSDUS_S)); \
     } while (0)

#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_RETRY_MSDUS_M     0xffff0000
#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_RETRY_MSDUS_S             16

#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_RETRY_MSDUS_GET(_var) \
    (((_var) & HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_RETRY_MSDUS_M) >> \
    HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_RETRY_MSDUS_S)

#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_RETRY_MSDUS_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_RETRY_MSDUS, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_RETRY_MSDUS_S)); \
     } while (0)

#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_FAILED_MSDUS_M     0x0000ffff
#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_FAILED_MSDUS_S              0

#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_FAILED_MSDUS_GET(_var) \
    (((_var) & HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_FAILED_MSDUS_M) >> \
    HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_FAILED_MSDUS_S)

#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_FAILED_MSDUS_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_FAILED_MSDUS, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_FAILED_MSDUS_S)); \
     } while (0)

#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_DUR_M     0xffff0000
#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_DUR_S             16

#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_DUR_GET(_var) \
    (((_var) & HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_DUR_M) >> \
    HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_DUR_S)

#define HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_DUR_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_DUR, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_ARRAY_ITEM_TLV_TX_DUR_S)); \
     } while (0)

PREPACK struct htt_tx_ppdu_stats_info {
    htt_tlv_hdr_t tlv_hdr;
    A_UINT32 tx_success_bytes;
    A_UINT32 tx_retry_bytes;
    A_UINT32 tx_failed_bytes;
    A_UINT32 tx_ratecode:       8,
             is_ampdu:          1,
             ba_ack_failed:     2,
             /*  0: 20 MHz
                 1: 40 MHz
                 2: 80 MHz
                 3: 160 MHz or 80+80 MHz */
             bw:                3,
             sgi:               1,
             reserved0:         1,
             peer_id:          16;
    A_UINT32 tx_success_msdus: 16,
             tx_retry_msdus:   16;
    A_UINT32 tx_failed_msdus:  16,
             /* united in us */
             tx_duration:      16;
} POSTPACK;

typedef struct {
    htt_tlv_hdr_t tlv_hdr;
    A_UINT32 number_of_ppdu_stats;
    /*
     * tx_ppdu_stats_info is filled by multiple struct htt_tx_ppdu_stats_info
     * elements.
     * tx_ppdu_stats_info is variable length, with length =
     *     number_of_ppdu_stats * sizeof (struct htt_tx_ppdu_stats_info)
     */
    A_UINT32 tx_ppdu_stats_info[1/*number_of_ppdu_stats*/];
} htt_ppdu_stats_usr_common_array_tlv_v;

typedef struct {
    htt_tlv_hdr_t tlv_hdr;

    /* Refer bmi_msg.h */
    A_UINT32 target_type;
    A_UINT32 hw[1]; /* Variable length, refer to struct scheduler_cmd_status */
} htt_ppdu_stats_sch_cmd_tlv_v;

#define HTT_PPDU_STATS_COMMON_TLV_SCH_CMDID_M     0x0000ffff
#define HTT_PPDU_STATS_COMMON_TLV_SCH_CMDID_S              0

#define HTT_PPDU_STATS_COMMON_TLV_SCH_CMDID_GET(_var) \
    (((_var) & HTT_PPDU_STATS_COMMON_TLV_SCH_CMDID_M) >> \
    HTT_PPDU_STATS_COMMON_TLV_SCH_CMDID_S)

#define HTT_PPDU_STATS_COMMON_TLV_SCH_CMDID_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_COMMON_TLV_SCH_CMDID, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_COMMON_TLV_SCH_CMDID_S)); \
     } while (0)

#define HTT_PPDU_STATS_COMMON_TLV_RING_ID_M     0x00ff0000
#define HTT_PPDU_STATS_COMMON_TLV_RING_ID_S             16

#define HTT_PPDU_STATS_COMMON_TLV_RING_ID_GET(_var) \
    (((_var) & HTT_PPDU_STATS_COMMON_TLV_RING_ID_M) >> \
    HTT_PPDU_STATS_COMMON_TLV_RING_ID_S)

#define HTT_PPDU_STATS_COMMON_TLV_RING_ID_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_COMMON_TLV_RING_ID, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_COMMON_TLV_RING_ID_S)); \
     } while (0)

#define HTT_PPDU_STATS_COMMON_TLV_NUM_USERS_M     0xff000000
#define HTT_PPDU_STATS_COMMON_TLV_NUM_USERS_S             24

#define HTT_PPDU_STATS_COMMON_TLV_NUM_USERS_GET(_var) \
    (((_var) & HTT_PPDU_STATS_COMMON_TLV_NUM_USERS_M) >> \
    HTT_PPDU_STATS_COMMON_TLV_NUM_USERS_S)

#define HTT_PPDU_STATS_COMMON_TLV_NUM_USERS_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_COMMON_TLV_NUM_USERS, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_COMMON_TLV_NUM_USERS_S)); \
     } while (0)

/* HW queue type */
enum HTT_TX_QUEUE_TYPE {
    HTT_TX_QUEUE_INACTIVE,
    HTT_TX_QUEUE_DATA,
    HTT_TX_QUEUE_BEACON,
    HTT_TX_QUEUE_PSPOLL,
    HTT_TX_QUEUE_CAB,
    HTT_TX_QUEUE_HALPHY,
    HTT_TX_QUEUE_QBOOST_RESP,
    HTT_TX_QUEUE_NAN_BEACON,
    HTT_TX_QUEUE_NAN_MGMT,
    HTT_TX_QUEUE_UL_DATA,
    HTT_TX_QUEUE_UL_BSR_RESP,
    HTT_TX_QUEUE_MGMT,
    HTT_TX_QUEUE_MAX,
};
typedef enum HTT_TX_QUEUE_TYPE HTT_TX_QUEUE_TYPE;

/* frame_type */
enum HTT_STATS_FTYPE {
    HTT_STATS_FTYPE_SGEN_NDPA = 0,
    HTT_STATS_FTYPE_SGEN_NDP,
    HTT_STATS_FTYPE_SGEN_BRP,
    HTT_STATS_FTYPE_SGEN_BAR,
    HTT_STATS_FTYPE_SGEN_RTS,
    HTT_STATS_FTYPE_SGEN_CTS,
    HTT_STATS_FTYPE_SGEN_CFEND,
    HTT_STATS_FTYPE_SGEN_AX_NDPA,
    HTT_STATS_FTYPE_SGEN_AX_NDP,
    HTT_STATS_FTYPE_SGEN_MU_TRIG,
    HTT_STATS_FTYPE_SGEN_MU_BAR,
    HTT_STATS_FTYPE_SGEN_MU_BRP,
    HTT_STATS_FTYPE_SGEN_MU_RTS,
    HTT_STATS_FTYPE_SGEN_MU_BSR,
    HTT_STATS_FTYPE_SGEN_UL_BSR,
    HTT_STATS_FTYPE_TIDQ_DATA_SU,
    HTT_STATS_FTYPE_TIDQ_DATA_MU,
    HTT_STATS_FTYPE_MAX,
};
typedef enum HTT_STATS_FTYPE HTT_STATS_FTYPE;

/* FRM_TYPE defined in HTT_STATS_FTYPE */
#define HTT_PPDU_STATS_COMMON_TLV_FRM_TYPE_M     0x000000ff
#define HTT_PPDU_STATS_COMMON_TLV_FRM_TYPE_S              0

#define HTT_PPDU_STATS_COMMON_TLV_FRM_TYPE_GET(_var) \
    (((_var) & HTT_PPDU_STATS_COMMON_TLV_FRM_TYPE_M) >> \
    HTT_PPDU_STATS_COMMON_TLV_FRM_TYPE_S)

#define HTT_PPDU_STATS_COMMON_TLV_FRM_TYPE_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_COMMON_TLV_FRM_TYPE, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_COMMON_TLV_FRM_TYPE_S)); \
     } while (0)

/* QTYPE defined in HTT_TX_QUEUE_TYPE */
#define HTT_PPDU_STATS_COMMON_TLV_QTYPE_M     0x0000ff00
#define HTT_PPDU_STATS_COMMON_TLV_QTYPE_S              8

#define HTT_PPDU_STATS_COMMON_TLV_QTYPE_GET(_var) \
    (((_var) & HTT_PPDU_STATS_COMMON_TLV_QTYPE_M) >> \
    HTT_PPDU_STATS_COMMON_TLV_QTYPE_S)

#define HTT_PPDU_STATS_COMMON_TLV_QTYPE_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_COMMON_TLV_QTYPE, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_COMMON_TLV_QTYPE_S)); \
     } while (0)


enum HTT_PPDU_STATS_BW {
    HTT_PPDU_STATS_BANDWIDTH_5MHZ   = 0,
    HTT_PPDU_STATS_BANDWIDTH_10MHZ  = 1,
    HTT_PPDU_STATS_BANDWIDTH_20MHZ  = 2,
    HTT_PPDU_STATS_BANDWIDTH_40MHZ  = 3,
    HTT_PPDU_STATS_BANDWIDTH_80MHZ  = 4,
    HTT_PPDU_STATS_BANDWIDTH_160MHZ = 5, /* includes 80+80 */
    HTT_PPDU_STATS_BANDWIDTH_DYN    = 6,
};
typedef enum HTT_PPDU_STATS_BW HTT_PPDU_STATS_BW;

#define HTT_PPDU_STATS_COMMON_TLV_BW_M     0x000f0000
#define HTT_PPDU_STATS_COMMON_TLV_BW_S             16

#define HTT_PPDU_STATS_COMMON_TLV_BW_GET(_var) \
    (((_var) & HTT_PPDU_STATS_COMMON_TLV_BW_M) >> \
    HTT_PPDU_STATS_COMMON_TLV_BW_S)

#define HTT_PPDU_STATS_COMMON_TLV_BW_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_COMMON_TLV_BW, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_COMMON_TLV_BW_S)); \
     } while (0)

#define HTT_PPDU_STATS_COMMON_TLV_PHY_MODE_M     0x0000ffff
#define HTT_PPDU_STATS_COMMON_TLV_PHY_MODE_S              0

#define HTT_PPDU_STATS_COMMON_TLV_PHY_MODE_GET(_var) \
    (((_var) & HTT_PPDU_STATS_COMMON_TLV_PHY_MODE_M) >> \
    HTT_PPDU_STATS_COMMON_TLV_PHY_MODE_S)

#define HTT_PPDU_STATS_COMMON_TLV_PHY_MODE_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_COMMON_TLV_PHY_MODE, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_COMMON_TLV_PHY_MODE_S)); \
     } while (0)

#define HTT_PPDU_STATS_COMMON_TLV_CHAN_MHZ_M     0xffff0000
#define HTT_PPDU_STATS_COMMON_TLV_CHAN_MHZ_S             16

#define HTT_PPDU_STATS_COMMON_TLV_CHAN_MHZ_GET(_var) \
    (((_var) & HTT_PPDU_STATS_COMMON_TLV_CHAN_MHZ_M) >> \
    HTT_PPDU_STATS_COMMON_TLV_CHAN_MHZ_S)

#define HTT_PPDU_STATS_COMMON_TLV_CHAN_MHZ_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_COMMON_TLV_CHAN_MHZ, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_COMMON_TLV_CHAN_MHZ_S)); \
     } while (0)

typedef struct {
    htt_tlv_hdr_t tlv_hdr;

    A_UINT32 ppdu_id;
    /* BIT [ 15 :   0]   :- sched_cmdid
     * BIT [ 23 :  16]   :- ring_id
     * BIT [ 31 :  24]   :- num_users
     */
    union {
        A_UINT32 ring_id__sched_cmdid;
        struct {
            A_UINT32 sched_cmdid:   16,
                     ring_id:        8,
                     num_users:      8;
        };
    };
    /* BIT [ 7 :   0]   :- frame_type - HTT_STATS_FTYPE
     * BIT [ 15:   8]   :- queue_type - HTT_TX_QUEUE_TYPE
     * BIT [ 19:  16]   :- bw - HTT_PPDU_STATS_BW
     * BIT [ 31:  20]   :- reserved
     */
    union {
        A_UINT32 bw__queue_type__frame_type;
        struct {
            A_UINT32 frame_type:     8,
                     queue_type:     8,
                     bw:             4,
                     reserved0:     12;
        };
    };
    A_UINT32 chain_mask;
    A_UINT32 fes_duration_us; /* frame exchange sequence */
    A_UINT32 ppdu_sch_eval_start_tstmp_us;
    A_UINT32 ppdu_sch_end_tstmp_us;
    A_UINT32 ppdu_start_tstmp_us;
    /* BIT [15 :  0] - phy mode (WLAN_PHY_MODE) with which ppdu was transmitted
     * BIT [31 : 16] - bandwidth (in MHz) with which ppdu was transmitted
     */
    union {
        A_UINT32 chan_mhz__phy_mode;
        struct {
            A_UINT32 phy_mode:     16,
                     chan_mhz:     16;
        };
    };
} htt_ppdu_stats_common_tlv;

#define HTT_PPDU_STATS_USER_COMMON_TLV_TID_NUM_M     0x000000ff
#define HTT_PPDU_STATS_USER_COMMON_TLV_TID_NUM_S              0

#define HTT_PPDU_STATS_USER_COMMON_TLV_TID_NUM_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_COMMON_TLV_TID_NUM_M) >> \
    HTT_PPDU_STATS_USER_COMMON_TLV_TID_NUM_S)

#define HTT_PPDU_STATS_USER_COMMON_TLV_TID_NUM_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_COMMON_TLV_TID_NUM, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_COMMON_TLV_TID_NUM_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_COMMON_TLV_VAP_ID_M     0x0000ff00
#define HTT_PPDU_STATS_USER_COMMON_TLV_VAP_ID_S              8

#define HTT_PPDU_STATS_USER_COMMON_TLV_VAP_ID_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_COMMON_TLV_VAP_ID_M) >> \
    HTT_PPDU_STATS_USER_COMMON_TLV_VAP_ID_S)

#define HTT_PPDU_STATS_USER_COMMON_TLV_VAP_ID_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_COMMON_TLV_VAP_ID, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_COMMON_TLV_VAP_ID_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_COMMON_TLV_SW_PEER_ID_M     0xffff0000
#define HTT_PPDU_STATS_USER_COMMON_TLV_SW_PEER_ID_S             16

#define HTT_PPDU_STATS_USER_COMMON_TLV_SW_PEER_ID_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_COMMON_TLV_SW_PEER_ID_M) >> \
    HTT_PPDU_STATS_USER_COMMON_TLV_SW_PEER_ID_S)

#define HTT_PPDU_STATS_USER_COMMON_TLV_SW_PEER_ID_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_COMMON_TLV_SW_PEER_ID, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_COMMON_TLV_SW_PEER_ID_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_COMMON_TLV_MCAST_M     0x00000001
#define HTT_PPDU_STATS_USER_COMMON_TLV_MCAST_S              0

#define HTT_PPDU_STATS_USER_COMMON_TLV_MCAST_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_COMMON_TLV_MCAST_M) >> \
    HTT_PPDU_STATS_USER_COMMON_TLV_MCAST_S)

#define HTT_PPDU_STATS_USER_COMMON_TLV_MCAST_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_COMMON_TLV_MCAST, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_COMMON_TLV_MCAST_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_COMMON_TLV_MPDUS_TRIED_M     0x000003fe
#define HTT_PPDU_STATS_USER_COMMON_TLV_MPDUS_TRIED_S              1

#define HTT_PPDU_STATS_USER_COMMON_TLV_MPDUS_TRIED_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_COMMON_TLV_MPDUS_TRIED_M) >> \
    HTT_PPDU_STATS_USER_COMMON_TLV_MPDUS_TRIED_S)

#define HTT_PPDU_STATS_USER_COMMON_TLV_MPDUS_TRIED_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_COMMON_TLV_MPDUS_TRIED, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_COMMON_TLV_MPDUS_TRIED_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_COMMON_TLV_BW_M     0x00003c00
#define HTT_PPDU_STATS_USER_COMMON_TLV_BW_S             10

#define HTT_PPDU_STATS_USER_COMMON_TLV_BW_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_COMMON_TLV_BW_M) >> \
    HTT_PPDU_STATS_USER_COMMON_TLV_BW_S)

#define HTT_PPDU_STATS_USER_COMMON_TLV_BW_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_COMMON_TLV_BW, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_COMMON_TLV_BW_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_COMMON_TLV_DELAYED_BA_M     0x00004000
#define HTT_PPDU_STATS_USER_COMMON_TLV_DELAYED_BA_S             14

#define HTT_PPDU_STATS_USER_COMMON_TLV_DELAYED_BA_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_COMMON_TLV_DELAYED_BA_M) >> \
    HTT_PPDU_STATS_USER_COMMON_TLV_DELAYED_BA_S)

#define HTT_PPDU_STATS_USER_COMMON_TLV_DELAYED_BA_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_COMMON_TLV_DELAYED_BA, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_COMMON_TLV_DELAYED_BA_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_COMMON_TLV_FRAME_CTRL_M     0x0000ffff
#define HTT_PPDU_STATS_USER_COMMON_TLV_FRAME_CTRL_S              0

#define HTT_PPDU_STATS_USER_COMMON_TLV_FRAME_CTRL_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_COMMON_TLV_FRAME_CTRL_M) >> \
    HTT_PPDU_STATS_USER_COMMON_TLV_FRAME_CTRL_S)

#define HTT_PPDU_STATS_USER_COMMON_TLV_FRAME_CTRL_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_COMMON_TLV_FRAME_CTRL, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_COMMON_TLV_FRAME_CTRL_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_COMMON_TLV_QOS_CTRL_M     0xffff0000
#define HTT_PPDU_STATS_USER_COMMON_TLV_QOS_CTRL_S             16

#define HTT_PPDU_STATS_USER_COMMON_TLV_QOS_CTRL_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_COMMON_TLV_QOS_CTRL_M) >> \
    HTT_PPDU_STATS_USER_COMMON_TLV_QOS_CTRL_S)

#define HTT_PPDU_STATS_USER_COMMON_TLV_QOS_CTRL_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_COMMON_TLV_QOS_CTRL, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_COMMON_TLV_QOS_CTRL_S)); \
     } while (0)

typedef struct {
    htt_tlv_hdr_t tlv_hdr;

    /* BIT [ 7 :   0]   :- tid_num
     * BIT [ 15:   8]   :- vap_id
     * BIT [ 31:  16]   :- sw_peer_id
     */
    union {
        A_UINT32 sw_peer_id__vapid__tid_num;
        struct {
            A_UINT32 tid_num:           8,
                     vap_id:            8,
                     sw_peer_id:       16;
        };
    };

    /* BIT [ 0 :    0]   :- mcast
     * BIT [ 9 :    1]   :- mpdus_tried
     * BIT [ 13:   10]   :- bw - HTT_PPDU_STATS_BW
     * BIT [ 14:   14]   : - delayed_ba
     * BIT [ 31:   15]   :- rsvd
     */
    union {
        A_UINT32 bw__mpdus_tried__mcast;
        struct {
            A_UINT32 mcast:              1,
                     mpdus_tried:        9,
                     bw:                 4,
                     delayed_ba:         1,
                     reserved0:         17;
        };
    };

    /* BIT [ 15:   0]   :- frame_ctrl
     * BIT [ 31:  16]   :- qos_ctrl
     */
    union {
        A_UINT32 qos_ctrl_frame_ctrl;
        struct {
            A_UINT32 frame_ctrl:       16,
                     qos_ctrl:         16;
        };
    };

} htt_ppdu_stats_user_common_tlv;

#define HTT_PPDU_STATS_USER_RATE_TLV_TID_NUM_M     0x000000ff
#define HTT_PPDU_STATS_USER_RATE_TLV_TID_NUM_S              0

#define HTT_PPDU_STATS_USER_RATE_TLV_TID_NUM_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_RATE_TLV_TID_NUM_M) >> \
    HTT_PPDU_STATS_USER_RATE_TLV_TID_NUM_S)

#define HTT_PPDU_STATS_USER_RATE_TLV_TID_NUM_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_RATE_TLV_TID_NUM, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_RATE_TLV_TID_NUM_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_RATE_TLV_RESERVED_M     0x0000ff00
#define HTT_PPDU_STATS_USER_RATE_TLV_RESERVED_S              8


#define HTT_PPDU_STATS_USER_RATE_TLV_SW_PEER_ID_M     0xffff0000
#define HTT_PPDU_STATS_USER_RATE_TLV_SW_PEER_ID_S             16

#define HTT_PPDU_STATS_USER_RATE_TLV_SW_PEER_ID_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_RATE_TLV_SW_PEER_ID_M) >> \
    HTT_PPDU_STATS_USER_RATE_TLV_SW_PEER_ID_S)

#define HTT_PPDU_STATS_USER_RATE_TLV_SW_PEER_ID_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_RATE_TLV_SW_PEER_ID, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_RATE_TLV_SW_PEER_ID_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_RATE_TLV_USER_POS_M     0x0000000f
#define HTT_PPDU_STATS_USER_RATE_TLV_USER_POS_S              0

#define HTT_PPDU_STATS_USER_RATE_TLV_USER_POS_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_RATE_TLV_USER_POS_M) >> \
    HTT_PPDU_STATS_USER_RATE_TLV_USER_POS_S)

#define HTT_PPDU_STATS_USER_RATE_TLV_USER_POS_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_RATE_TLV_USER_POS, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_RATE_TLV_USER_POS_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_RATE_TLV_MU_GROUPID_M     0x00000ff0
#define HTT_PPDU_STATS_USER_RATE_TLV_MU_GROUPID_S              4

#define HTT_PPDU_STATS_USER_RATE_TLV_MU_GROUPID_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_RATE_TLV_MU_GROUPID_M) >> \
    HTT_PPDU_STATS_USER_RATE_TLV_MU_GROUPID_S)

#define HTT_PPDU_STATS_USER_RATE_TLV_MU_GROUPID_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_RATE_TLV_MU_GROUPID, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_RATE_TLV_MU_GROUPID_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_RATE_TLV_RU_END_M     0x0000ffff
#define HTT_PPDU_STATS_USER_RATE_TLV_RU_END_S              0

#define HTT_PPDU_STATS_USER_RATE_TLV_RU_END_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_RATE_TLV_RU_END_M) >> \
    HTT_PPDU_STATS_USER_RATE_TLV_RU_END_S)

#define HTT_PPDU_STATS_USER_RATE_TLV_RU_END_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_RATE_TLV_RU_END, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_RATE_TLV_RU_END_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_RATE_TLV_RU_START_M     0xffff0000
#define HTT_PPDU_STATS_USER_RATE_TLV_RU_START_S             16

#define HTT_PPDU_STATS_USER_RATE_TLV_RU_START_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_RATE_TLV_RU_START_M) >> \
    HTT_PPDU_STATS_USER_RATE_TLV_RU_START_S)

#define HTT_PPDU_STATS_USER_RATE_TLV_RU_START_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_RATE_TLV_RU_START, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_RATE_TLV_RU_START_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_RATE_TLV_RESP_TYPE_VALID_M     0x00000001
#define HTT_PPDU_STATS_USER_RATE_TLV_RESP_TYPE_VALID_S              0

#define HTT_PPDU_STATS_USER_RATE_TLV_RESP_TYPE_VALID_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_RATE_TLV_RESP_TYPE_VALID_M) >> \
    HTT_PPDU_STATS_USER_RATE_TLV_RESP_TYPE_VALID_S)

#define HTT_PPDU_STATS_USER_RATE_TLV_RESP_TYPE_VALID_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_RATE_TLV_RESP_TYPE_VALID, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_RATE_TLV_RESP_TYPE_VALID_S)); \
     } while (0)

enum HTT_PPDU_STATS_PPDU_TYPE {
    HTT_PPDU_STATS_PPDU_TYPE_SU,
    HTT_PPDU_STATS_PPDU_TYPE_MU_MIMO,
    HTT_PPDU_STATS_PPDU_TYPE_MU_OFDMA,
    HTT_PPDU_STATS_PPDU_TYPE_MU_MIMO_OFDMA,
    HTT_PPDU_STATS_PPDU_TYPE_UL_TRIG,
    HTT_PPDU_STATS_PPDU_TYPE_BURST_BCN,
    HTT_PPDU_STATS_PPDU_TYPE_UL_BSR_RESP,
    HTT_PPDU_STATS_PPDU_TYPE_UL_BSR_TRIG,
    HTT_PPDU_STATS_PPDU_TYPE_UL_RESP,

    HTT_PPDU_STATS_PPDU_TYPE_UNKNOWN = 0x1F,
};
typedef enum HTT_PPDU_STATS_PPDU_TYPE HTT_PPDU_STATS_PPDU_TYPE;

#define HTT_PPDU_STATS_USER_RATE_TLV_PPDU_TYPE_M     0x0000003E
#define HTT_PPDU_STATS_USER_RATE_TLV_PPDU_TYPE_S              1

#define HTT_PPDU_STATS_USER_RATE_TLV_PPDU_TYPE_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_RATE_TLV_PPDU_TYPE_M) >> \
    HTT_PPDU_STATS_USER_RATE_TLV_PPDU_TYPE_S)

#define HTT_PPDU_STATS_USER_RATE_TLV_PPDU_TYPE_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_RATE_TLV_PPDU_TYPE, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_RATE_TLV_PPDU_TYPE_S)); \
     } while (0)

enum HTT_PPDU_STATS_TXBF_TYPE {
    HTT_PPDU_STATS_TXBF_OPEN_LOOP,
    HTT_PPDU_STATS_TXBF_IMPLICIT,
    HTT_PPDU_STATS_TXBF_EXPLICIT,
    HTT_PPDU_STATS_TXBF_MAX,
};

#define HTT_PPDU_STATS_USER_RATE_TLV_LTF_SIZE_M     0x00000003
#define HTT_PPDU_STATS_USER_RATE_TLV_LTF_SIZE_S              0

#define HTT_PPDU_STATS_USER_RATE_TLV_LTF_SIZE_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_RATE_TLV_LTF_SIZE_M) >> \
    HTT_PPDU_STATS_USER_RATE_TLV_LTF_SIZE_S)

#define HTT_PPDU_STATS_USER_RATE_TLV_LTF_SIZE_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_RATE_TLV_LTF_SIZE, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_RATE_TLV_LTF_SIZE_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_RATE_TLV_STBC_M     0x00000004
#define HTT_PPDU_STATS_USER_RATE_TLV_STBC_S              2

#define HTT_PPDU_STATS_USER_RATE_TLV_STBC_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_RATE_TLV_STBC_M) >> \
    HTT_PPDU_STATS_USER_RATE_TLV_STBC_S)

#define HTT_PPDU_STATS_USER_RATE_TLV_STBC_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_RATE_TLV_STBC, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_RATE_TLV_STBC_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_RATE_TLV_HE_RE_M     0x00000008
#define HTT_PPDU_STATS_USER_RATE_TLV_HE_RE_S              3

#define HTT_PPDU_STATS_USER_RATE_TLV_HE_RE_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_RATE_TLV_HE_RE_M) >> \
    HTT_PPDU_STATS_USER_RATE_TLV_HE_RE_S)

#define HTT_PPDU_STATS_USER_RATE_TLV_HE_RE_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_RATE_TLV_HE_RE, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_RATE_TLV_HE_RE_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_RATE_TLV_TXBF_M     0x000000f0
#define HTT_PPDU_STATS_USER_RATE_TLV_TXBF_S              4

#define HTT_PPDU_STATS_USER_RATE_TLV_TXBF_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_RATE_TLV_TXBF_M) >> \
    HTT_PPDU_STATS_USER_RATE_TLV_TXBF_S)

#define HTT_PPDU_STATS_USER_RATE_TLV_TXBF_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_RATE_TLV_TXBF, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_RATE_TLV_TXBF_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_RATE_TLV_BW_M     0x00000f00
#define HTT_PPDU_STATS_USER_RATE_TLV_BW_S              8

#define HTT_PPDU_STATS_USER_RATE_TLV_BW_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_RATE_TLV_BW_M) >> \
    HTT_PPDU_STATS_USER_RATE_TLV_BW_S)

#define HTT_PPDU_STATS_USER_RATE_TLV_BW_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_RATE_TLV_BW, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_RATE_TLV_BW_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_RATE_TLV_NSS_M     0x0000f000
#define HTT_PPDU_STATS_USER_RATE_TLV_NSS_S             12

#define HTT_PPDU_STATS_USER_RATE_TLV_NSS_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_RATE_TLV_NSS_M) >> \
    HTT_PPDU_STATS_USER_RATE_TLV_NSS_S)

#define HTT_PPDU_STATS_USER_RATE_TLV_NSS_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_RATE_TLV_NSS, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_RATE_TLV_NSS_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_RATE_TLV_MCS_M     0x000f0000
#define HTT_PPDU_STATS_USER_RATE_TLV_MCS_S             16

#define HTT_PPDU_STATS_USER_RATE_TLV_MCS_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_RATE_TLV_MCS_M) >> \
    HTT_PPDU_STATS_USER_RATE_TLV_MCS_S)

#define HTT_PPDU_STATS_USER_RATE_TLV_MCS_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_RATE_TLV_MCS, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_RATE_TLV_MCS_S)); \
     } while (0)

/* Refer HTT_STATS_PREAM_TYPE */
#define HTT_PPDU_STATS_USER_RATE_TLV_PREAMBLE_M     0x00f00000
#define HTT_PPDU_STATS_USER_RATE_TLV_PREAMBLE_S             20

#define HTT_PPDU_STATS_USER_RATE_TLV_PREAMBLE_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_RATE_TLV_PREAMBLE_M) >> \
    HTT_PPDU_STATS_USER_RATE_TLV_PREAMBLE_S)

#define HTT_PPDU_STATS_USER_RATE_TLV_PREAMBLE_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_RATE_TLV_PREAMBLE, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_RATE_TLV_PREAMBLE_S)); \
     } while (0)

/* Guard Intervals */
enum HTT_PPDU_STATS_GI {
    HTT_PPDU_STATS_GI_800,
    HTT_PPDU_STATS_GI_400,
    HTT_PPDU_STATS_GI_1600,
    HTT_PPDU_STATS_GI_3200,
    HTT_PPDU_STATS_GI_CNT,
};
typedef enum HTT_PPDU_STATS_GI HTT_PPDU_STATS_GI;

/* Refer HTT_PPDU_STATS_GI */
#define HTT_PPDU_STATS_USER_RATE_TLV_GI_M     0x0f000000
#define HTT_PPDU_STATS_USER_RATE_TLV_GI_S             24

#define HTT_PPDU_STATS_USER_RATE_TLV_GI_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_RATE_TLV_GI_M) >> \
    HTT_PPDU_STATS_USER_RATE_TLV_GI_S)

#define HTT_PPDU_STATS_USER_RATE_TLV_GI_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_RATE_TLV_GI, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_RATE_TLV_GI_S)); \
     } while (0)


#define HTT_PPDU_STATS_USER_RATE_TLV_DCM_M     0x10000000
#define HTT_PPDU_STATS_USER_RATE_TLV_DCM_S             28

#define HTT_PPDU_STATS_USER_RATE_TLV_DCM_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_RATE_TLV_DCM_M) >> \
    HTT_PPDU_STATS_USER_RATE_TLV_DCM_S)

#define HTT_PPDU_STATS_USER_RATE_TLV_DCM_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_RATE_TLV_DCM, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_RATE_TLV_DCM_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_RATE_TLV_LDPC_M     0x20000000
#define HTT_PPDU_STATS_USER_RATE_TLV_LDPC_S             29

#define HTT_PPDU_STATS_USER_RATE_TLV_LDPC_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_RATE_TLV_LDPC_M) >> \
    HTT_PPDU_STATS_USER_RATE_TLV_LDPC_S)

#define HTT_PPDU_STATS_USER_RATE_TLV_LDPC_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_RATE_TLV_LDPC, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_RATE_TLV_LDPC_S)); \
     } while (0)

enum HTT_PPDU_STATS_RESP_PPDU_TYPE {
    HTT_PPDU_STATS_RESP_PPDU_TYPE_MU_MIMO_UL,
    HTT_PPDU_STATS_RESP_PPDU_TYPE_MU_OFDMA_UL,
};
typedef enum HTT_PPDU_STATS_RESP_PPDU_TYPE HTT_PPDU_STATS_RESP_PPDU_TYPE;

#define HTT_PPDU_STATS_USER_RATE_TLV_RESP_PPDU_TYPE_M     0xC0000000
#define HTT_PPDU_STATS_USER_RATE_TLV_RESP_PPDU_TYPE_S             30

#define HTT_PPDU_STATS_USER_RATE_TLV_RESP_PPDU_TYPE_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_RATE_TLV_RESP_PPDU_TYPE_M) >> \
    HTT_PPDU_STATS_USER_RATE_TLV_RESP_PPDU_TYPE_S)

#define HTT_PPDU_STATS_USER_RATE_TLV_RESP_PPDU_TYPE_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_RATE_TLV_RESP_PPDU_TYPE, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_RATE_TLV_RESP_PPDU_TYPE_S)); \
     } while (0)


typedef struct {
    htt_tlv_hdr_t tlv_hdr;

    /* BIT [ 7 :   0]   :- tid_num
     * BIT [ 15:   8]   :- reserved0
     * BIT [ 31:  16]   :- sw_peer_id
     */
    union {
        A_UINT32 sw_peer_id__tid_num;
        struct {
            A_UINT32 tid_num:            8,
                     reserved0:          8,
                     sw_peer_id:        16;
        };
    };

    /* BIT [ 3 :   0]   :- user_pos
     * BIT [ 11:   4]   :- mu_group_id
     * BIT [ 31:  12]   :- reserved1
     */
    union {
        A_UINT32 mu_group_id__user_pos;
        struct {
            A_UINT32 user_pos:           4,
                     mu_group_id:        8,
                     reserved1:         20;
        };
    };

    /* BIT [ 15 :   0]   :- ru_end
     * BIT [ 31 :  16]   :- ru_start
     */
    union {
        A_UINT32 ru_start__ru_end;
        struct {
            A_UINT32 ru_end:            16,
                     ru_start:          16;
        };
    };

    /* BIT [ 15 :   0]   :- ru_end
     * BIT [ 31 :  16]   :- ru_start
     */
    union {
        A_UINT32 resp_ru_start__ru_end;
        struct {
            A_UINT32 resp_ru_end:       16,
                     resp_ru_start:     16;
        };
    };

    /* BIT [ 0 :   0 ]   :- resp_type_valid
     * BIT [ 5 :   1 ]   :- ppdu_type - HTT_PPDU_STAT_PPDU_TYPE
     * BIT [ 31:   6 ]   :- reserved2
     */
    union {
        A_UINT32 resp_type_vld_ppdu_type;
        struct {
            A_UINT32 resp_type_vld:      1,
                     ppdu_type:          5,
                     reserved2:         26;
        };
    };

    /* BIT [ 1 :   0 ]   :- ltf_size
     * BIT [ 2 :   2 ]   :- stbc
     * BIT [ 3 :   3 ]   :- he_re (range extension)
     * BIT [ 7 :   4 ]   :- txbf
     * BIT [ 11:   8 ]   :- bw
     * BIT [ 15:   12]   :- nss  NSS 1,2, ...8
     * BIT [ 19:   16]   :- mcs
     * BIT [ 23:   20]   :- preamble
     * BIT [ 27:   24]   :- gi - HTT_PPDU_STATS_GI
     * BIT [ 28:   28]   :- dcm
     * BIT [ 29:   29]   :- ldpc
     * BIT [ 31:   30]   :- reserved4
     */
    union {
        A_UINT32 rate_info;
        struct {
            A_UINT32 ltf_size:           2,
                     stbc:               1,
                     he_re:              1,
                     txbf:               4,
                     bw:                 4,
                     nss:                4,
                     mcs:                4,
                     preamble:           4,
                     gi:                 4,
                     dcm:                1,
                     ldpc:               1,
                     reserved4:          2;
        };
    };

    /* Note: resp_rate_info is only valid for if resp_type is UL
     * BIT [ 1 :   0 ]   :- ltf_size
     * BIT [ 2 :   2 ]   :- stbc
     * BIT [ 3 :   3 ]   :- he_re (range extension)
     * BIT [ 7 :   4 ]   :- reserved3
     * BIT [ 11:   8 ]   :- bw
     * BIT [ 15:   12]   :- nss  NSS 1,2, ...8
     * BIT [ 19:   16]   :- mcs
     * BIT [ 23:   20]   :- preamble
     * BIT [ 27:   24]   :- gi
     * BIT [ 28:   28]   :- dcm
     * BIT [ 29:   29]   :- ldpc
     * BIT [ 31:   30]   :- resp_ppdu_type - HTT_PPDU_STATS_RESP_PPDU_TYPE
     */
    union {
        A_UINT32 resp_rate_info;
        struct {
            A_UINT32 resp_ltf_size:           2,
                     resp_stbc:               1,
                     resp_he_re:              1,
                     reserved3:               4,
                     resp_bw:                 4,
                     resp_nss:                4,
                     resp_mcs:                4,
                     resp_preamble:           4,
                     resp_gi:                 4,
                     resp_dcm:                1,
                     resp_ldpc:               1,
                     resp_ppdu_type:          2;
        };
    };
} htt_ppdu_stats_user_rate_tlv;

#define HTT_PPDU_STATS_ENQ_MPDU_BITMAP_TLV_TID_NUM_M     0x000000ff
#define HTT_PPDU_STATS_ENQ_MPDU_BITMAP_TLV_TID_NUM_S              0

#define HTT_PPDU_STATS_ENQ_MPDU_BITMAP_TLV_TID_NUM_GET(_var) \
    (((_var) & HTT_PPDU_STATS_EMQ_MPDU_BITMAP_TLV_TID_NUM_M) >> \
    HTT_PPDU_STATS_ENQ_MPDU_BITMAP_TLV_TID_NUM_S)

#define HTT_PPDU_STATS_ENQ_MPDU_BITMAP_TLV_TID_NUM_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_ENQ_MPDU_BITMAP_TLV_TID_NUM, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_ENQ_MPDU_BITMAP_TLV_TID_NUM_S)); \
     } while (0)

#define HTT_PPDU_STATS_ENQ_MPDU_BITMAP_TLV_RESERVED_M     0x0000ff00
#define HTT_PPDU_STATS_ENQ_MPDU_BITMAP_TLV_RESERVED_S              8


#define HTT_PPDU_STATS_ENQ_MPDU_BITMAP_TLV_SW_PEER_ID_M     0xffff0000
#define HTT_PPDU_STATS_ENQ_MPDU_BITMAP_TLV_SW_PEER_ID_S             16

#define HTT_PPDU_STATS_ENQ_MPDU_BITMAP_TLV_SW_PEER_ID_GET(_var) \
    (((_var) & HTT_PPDU_STATS_ENQ_MPDU_BITMAP_TLV_SW_PEER_ID_M) >> \
    HTT_PPDU_STATS_ENQ_MPDU_BITMAP_TLV_SW_PEER_ID_S)

#define HTT_PPDU_STATS_ENQ_MPDU_BITMAP_TLV_SW_PEER_ID_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_ENQ_MPDU_BITMAP_TLV_SW_PEER_ID, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_ENQ_MPDU_BITMAP_TLV_SW_PEER_ID_S)); \
     } while (0)

typedef struct {
    htt_tlv_hdr_t tlv_hdr;
    /* BIT [ 7 :   0]   :- tid_num
     * BIT [ 15:   8]   :- reserved0
     * BIT [ 31:  16]   :- sw_peer_id
     */
    union {
        A_UINT32 sw_peer_id__tid_num;
        struct {
            A_UINT32 tid_num:         8,
                     reserved0:       8,
                     sw_peer_id:     16;
        };
    };
    A_UINT32 start_seq;
    A_UINT32 enq_bitmap[HTT_BA_64_BIT_MAP_SIZE_DWORDS];
} htt_ppdu_stats_enq_mpdu_bitmap_64_tlv;

typedef struct {
    htt_tlv_hdr_t tlv_hdr;
    /* BIT [ 7 :   0]   :- tid_num
     * BIT [ 15:   8]   :- reserved0
     * BIT [ 31:  16]   :- sw_peer_id
     */
    union {
        A_UINT32 sw_peer_id__tid_num;
        struct {
            A_UINT32 tid_num:         8,
                     reserved0:       8,
                     sw_peer_id:     16;
        };
    };
    A_UINT32 start_seq;
    A_UINT32 enq_bitmap[HTT_BA_256_BIT_MAP_SIZE_DWORDS];
} htt_ppdu_stats_enq_mpdu_bitmap_256_tlv;

/* COMPLETION_STATUS defined in HTT_PPDU_STATS_USER_COMPLETION_STATUS */
#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_COMPLETION_STATUS_M     0x000000ff
#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_COMPLETION_STATUS_S              0

#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_COMPLETION_STATUS_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_COMPLETION_STATUS_M) >> \
    HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_COMPLETION_STATUS_S)

#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_COMPLETION_STATUS_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_COMPLETION_STATUS, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_COMPLETION_STATUS_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_TID_NUM_M     0x0000ff00
#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_TID_NUM_S              8

#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_TID_NUM_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_TID_NUM_M) >> \
    HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_TID_NUM_S)

#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_TID_NUM_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_TID_NUM, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_TID_NUM_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_SW_PEER_ID_M     0xffff0000
#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_SW_PEER_ID_S             16

#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_SW_PEER_ID_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_SW_PEER_ID_M) >> \
    HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_SW_PEER_ID_S)

#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_SW_PEER_ID_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_SW_PEER_ID, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_SW_PEER_ID_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_MPDU_TRIED_M     0x0000ffff
#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_MPDU_TRIED_S              0

#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_MPDU_TRIED_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_MPDU_TRIED_M) >> \
    HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_MPDU_TRIED_S)

#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_MPDU_TRIED_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_MPDU_TRIED, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_MPDU_TRIED_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_MPDU_SUCCESS_M     0xffff0000
#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_MPDU_SUCCESS_S             16

#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_MPDU_SUCCESS_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_MPDU_SUCCESS_M) >> \
    HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_MPDU_SUCCESS_S)

#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_MPDU_SUCCESS_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_MPDU_SUCCESS, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_MPDU_SUCCESS_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_LONG_RETRY_M     0x0000000f
#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_LONG_RETRY_S              0

#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_LONG_RETRY_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_LONG_RETRY_M) >> \
    HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_LONG_RETRY_S)

#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_LONG_RETRY_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_LONG_RETRY, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_LONG_RETRY_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_SHORT_RETRY_M     0x000000f0
#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_SHORT_RETRY_S              4

#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_SHORT_RETRY_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_SHORT_RETRY_M) >> \
    HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_SHORT_RETRY_S)

#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_SHORT_RETRY_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_SHORT_RETRY, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_SHORT_RETRY_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_IS_AMPDU_M     0x00000100
#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_IS_AMPDU_S              8

#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_IS_AMPDU_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_IS_AMPDU_M) >> \
    HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_IS_AMPDU_S)

#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_IS_AMPDU_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_IS_AMPDU, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_IS_AMPDU_S)); \
     } while (0)

enum HTT_PPDU_STATS_RESP_TYPE {
    HTT_PPDU_STATS_NO_RESPONSE_EXPECTED_E                      = 0,
    HTT_PPDU_STATS_ACK_EXPECTED_E                              = 1,
    HTT_PPDU_STATS_BA_BITMAP_EXPECTED_E                        = 2,
    HTT_PPDU_STATS_UL_MU_BA_EXPECTED_E                         = 3,
    HTT_PPDU_STATS_UL_MU_BA_AND_DATA_EXPECTED_E                = 4,
    HTT_PPDU_STATS_CTS_EXPECTED_E                              = 5,
    HTT_PPDU_STATS_MU_CBF_EXPECTED_E                           = 6,
};
typedef enum HTT_PPDU_STATS_RESP_TYPE HTT_PPDU_STATS_RESP_TYPE;

/* Refer HTT_PPDU_STATS_RESP_TYPE */
#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_RESP_TYPE_M     0x00001e00
#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_RESP_TYPE_S              9

#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_RESP_TYPE_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_RESP_TYPE_M) >> \
    HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_RESP_TYPE_S)

#define HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_RESP_TYPE_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_RESP_TYPE, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_CMPLTN_COMMON_TLV_RESP_TYPE_S)); \
     } while (0)

enum  HTT_PPDU_STATS_USER_COMPLETION_STATUS {
    HTT_PPDU_STATS_USER_STATUS_OK,
    HTT_PPDU_STATS_USER_STATUS_FILTERED,
    HTT_PPDU_STATS_USER_STATUS_RESP_TIMEOUT,
    HTT_PPDU_STATS_USER_STATUS_RESP_MISMATCH,
    HTT_PPDU_STATS_USER_STATUS_ABORT,
};
typedef enum HTT_PPDU_STATS_USER_COMPLETION_STATUS HTT_PPDU_STATS_USER_COMPLETION_STATUS;

typedef struct {
    htt_tlv_hdr_t tlv_hdr;
    /* BIT [ 7 :   0]   :- completion_status
     * BIT [ 15:   8]   :- tid_num
     * BIT [ 31:  16]   :- sw_peer_id
     */
    union {
        A_UINT32 sw_peer_id__tid_num__completion_status;
        struct {
            A_UINT32 completion_status:         8,
                     tid_num:                   8,
                     sw_peer_id:               16;
        };
    };

    /* RSSI value of last ack packet (units = dB above noise floor) */
    A_UINT32 ack_rssi;

    /* BIT [ 15 :   0]   :- mpdu_tried
     * BIT [ 31 :  16]   :- mpdu_success
     */
    union {
        A_UINT32 mpdu_tried__mpdu_success;
        struct {
            A_UINT32 mpdu_tried:                16,
                     mpdu_success:              16;
        };
    };

    /* BIT [ 3 :   0]   :- long_retries
     * BIT [ 7 :   4]   :- short_retries
     * BIT [ 8 :   8]   :- is_ampdu
     * BIT [ 12:   9]   :- resp_type
     * BIT [ 31:  13]   :- reserved0
     */
    union {
        A_UINT32 resp_type_is_ampdu__short_retry__long_retry;
        struct {
            A_UINT32 long_retries:               4,
                     short_retries:              4,
                     is_ampdu:                   1,
                     resp_type:                  4,
                     reserved0:                 19;
        };
    };
} htt_ppdu_stats_user_cmpltn_common_tlv;

#define HTT_PPDU_STATS_USER_CMPLTN_BA_BITMAP_TLV_TID_NUM_M     0x000000ff
#define HTT_PPDU_STATS_USER_CMPLTN_BA_BITMAP_TLV_TID_NUM_S              0

#define HTT_PPDU_STATS_USER_CMPLTN_BA_BITMAP_TLV_TID_NUM_GET(_var) \
    (((_var) & HTT_PPDU_STATS_EMQ_MPDU_BITMAP_TLV_TID_NUM_M) >> \
    HTT_PPDU_STATS_USER_CMPLTN_BA_BITMAP_TLV_TID_NUM_S)

#define HTT_PPDU_STATS_USER_CMPLTN_BA_BITMAP_TLV_TID_NUM_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_CMPLTN_BA_BITMAP_TLV_TID_NUM, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_CMPLTN_BA_BITMAP_TLV_TID_NUM_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_CMPLTN_BA_BITMAP_TLV_RESERVED_M     0x0000ff00
#define HTT_PPDU_STATS_USER_CMPLTN_BA_BITMAP_TLV_RESERVED_S              8


#define HTT_PPDU_STATS_USER_CMPLTN_BA_BITMAP_TLV_SW_PEER_ID_M     0xffff0000
#define HTT_PPDU_STATS_USER_CMPLTN_BA_BITMAP_TLV_SW_PEER_ID_S             16

#define HTT_PPDU_STATS_USER_CMPLTN_BA_BITMAP_TLV_SW_PEER_ID_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_CMPLTN_BA_BITMAP_TLV_SW_PEER_ID_M) >> \
    HTT_PPDU_STATS_USER_CMPLTN_BA_BITMAP_TLV_SW_PEER_ID_S)

#define HTT_PPDU_STATS_USER_CMPLTN_BA_BITMAP_TLV_SW_PEER_ID_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_CMPLTN_BA_BITMAP_TLV_SW_PEER_ID, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_CMPLTN_BA_BITMAP_TLV_SW_PEER_ID_S)); \
     } while (0)


typedef struct {
    htt_tlv_hdr_t tlv_hdr;
    /* BIT [ 7 :   0]   :- tid_num
     * BIT [ 15:   8]   :- reserved0
     * BIT [ 31:  16]   :- sw_peer_id
     */
    union {
        A_UINT32 sw_peer_id__tid_num;
        struct {
            A_UINT32 tid_num:        8,
                     reserved0:      8,
                     sw_peer_id:    16;
        };
    };
    A_UINT32 ba_seq_no;
    A_UINT32 ba_bitmap[HTT_BA_64_BIT_MAP_SIZE_DWORDS];
} htt_ppdu_stats_user_compltn_ba_bitmap_64_tlv;

typedef struct {
    htt_tlv_hdr_t tlv_hdr;
    /* BIT [ 7 :   0]   :- tid_num
     * BIT [ 15:   8]   :- reserved0
     * BIT [ 31:  16]   :- sw_peer_id
     */
    union {
        A_UINT32 sw_peer_id__tid_num;
        struct {
            A_UINT32 tid_num:        8,
                     reserved0:      8,
                     sw_peer_id:    16;
        };
    };
    A_UINT32 ba_seq_no;
    A_UINT32 ba_bitmap[HTT_BA_256_BIT_MAP_SIZE_DWORDS];
} htt_ppdu_stats_user_compltn_ba_bitmap_256_tlv;

#define HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_SW_PEER_ID_M     0x0000ffff
#define HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_SW_PEER_ID_S              0

#define HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_SW_PEER_ID_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_SW_PEER_ID_M) >> \
    HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_SW_PEER_ID_S)

#define HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_SW_PEER_ID_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_SW_PEER_ID, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_SW_PEER_ID_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_NUM_MPDU_M     0x000001ff
#define HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_NUM_MPDU_S              0

#define HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_NUM_MPDU_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_NUM_MPDU_M) >> \
    HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_NUM_MPDU_S)

#define HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_NUM_MPDU_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_NUM_MPDU, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_NUM_MPDU_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_NUM_MSDU_M     0x01fffe00
#define HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_NUM_MSDU_S              9

#define HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_NUM_MSDU_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_NUM_MSDU_M) >> \
    HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_NUM_MSDU_S)

#define HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_NUM_MSDU_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_NUM_MSDU, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_NUM_MSDU_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_TID_NUM_M     0xfe000000
#define HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_TID_NUM_S             25

#define HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_TID_NUM_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_TID_NUM_M) >> \
    HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_TID_NUM_S)

#define HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_TID_NUM_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_TID_NUM, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_TID_NUM_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_CUR_SEQ_M     0x0000ffff
#define HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_CUR_SEQ_S              0

#define HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_CUR_SEQ_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_CUR_SEQ_M) >> \
    HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_CUR_SEQ_S)

#define HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_CUR_SEQ_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_CUR_SEQ, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_CUR_SEQ_S)); \
     } while (0)

#define HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_START_SEQ_M     0xffff0000
#define HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_START_SEQ_S             16

#define HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_START_SEQ_GET(_var) \
    (((_var) & HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_START_SEQ_M) >> \
    HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_START_SEQ_S)

#define HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_START_SEQ_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_START_SEQ, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_USER_CMPLTN_ACK_BA_STATUS_TLV_START_SEQ_S)); \
     } while (0)

typedef struct {
    htt_tlv_hdr_t tlv_hdr;
    A_UINT32 ppdu_id;

    /* BIT [ 15 :   0]   :- sw_peer_id
     * BIT [ 31 :  16]   :- reserved0
     */
    union {
        A_UINT32 rsvd_sw_peer_id;
        struct {
            A_UINT32 sw_peer_id:          16,
                     reserved0:           16;
        };
    };

    /* BIT [ 8  :   0]   :- num_mpdu
     * BIT [ 24 :   9]   :- num_msdu
     * BIT [ 31 :  25]   :- tid_num
     */
    union {
        A_UINT32 tid_num__num_msdu__num_mpdu;
        struct {
            A_UINT32 num_mpdu:             9,
                     num_msdu:            16,
                     tid_num:              7;
        };
    };

    /* BIT [ 15 :   0]   :- current_seq
     * BIT [ 31 :  16]   :- start_seq
     */
    union {
        A_UINT32 start_seq__current_seq;
        struct {
            A_UINT32 current_seq:          16,
                     start_seq:            16;
        };
    };

    A_UINT32 success_bytes;
} htt_ppdu_stats_user_compltn_ack_ba_status_tlv;

/* FLOW_TYPE defined in HTT_TX_FLOW_TYPE */
#define HTT_PPDU_STATS_FLUSH_TLV_FLOW_TYPE_M     0x000000ff
#define HTT_PPDU_STATS_FLUSH_TLV_FLOW_TYPE_S              0

#define HTT_PPDU_STATS_FLUSH_TLV_FLOW_TYPE_GET(_var) \
    (((_var) & HTT_PPDU_STATS_FLUSH_TLV_FLOW_TYPE_M) >> \
    HTT_PPDU_STATS_FLUSH_TLV_FLOW_TYPE_S)

#define HTT_PPDU_STATS_FLUSH_TLV_FLOW_TYPE_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_FLUSH_TLV_FLOW_TYPE, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_FLUSH_TLV_FLOW_TYPE_S)); \
     } while (0)

#define HTT_PPDU_STATS_FLUSH_TLV_NUM_MPDU_M     0x0001ff00
#define HTT_PPDU_STATS_FLUSH_TLV_NUM_MPDU_S              8

#define HTT_PPDU_STATS_FLUSH_TLV_NUM_MPDU_GET(_var) \
    (((_var) & HTT_PPDU_STATS_FLUSH_TLV_NUM_MPDU_M) >> \
    HTT_PPDU_STATS_FLUSH_TLV_NUM_MPDU_S)

#define HTT_PPDU_STATS_FLUSH_TLV_NUM_MPDU_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_FLUSH_TLV_NUM_MPDU, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_FLUSH_TLV_NUM_MPDU_S)); \
     } while (0)

#define HTT_PPDU_STATS_FLUSH_TLV_NUM_MSDU_M     0x7ffe0000
#define HTT_PPDU_STATS_FLUSH_TLV_NUM_MSDU_S             17

#define HTT_PPDU_STATS_FLUSH_TLV_NUM_MSDU_GET(_var) \
    (((_var) & HTT_PPDU_STATS_FLUSH_TLV_NUM_MSDU_M) >> \
    HTT_PPDU_STATS_FLUSH_TLV_NUM_MSDU_S)

#define HTT_PPDU_STATS_FLUSH_TLV_NUM_MSDU_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_FLUSH_TLV_NUM_MSDU, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_FLUSH_TLV_NUM_MSDU_S)); \
     } while (0)

#define HTT_PPDU_STATS_FLUSH_TLV_TID_NUM_M     0x000000ff
#define HTT_PPDU_STATS_FLUSH_TLV_TID_NUM_S              0

#define HTT_PPDU_STATS_FLUSH_TLV_TID_NUM_GET(_var) \
    (((_var) & HTT_PPDU_STATS_FLUSH_TLV_TID_NUM_M) >> \
    HTT_PPDU_STATS_FLUSH_TLV_TID_NUM_S)

#define HTT_PPDU_STATS_FLUSH_TLV_TID_NUM_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_FLUSH_TLV_TID_NUM, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_FLUSH_TLV_TID_NUM_S)); \
     } while (0)

#define HTT_PPDU_STATS_FLUSH_TLV_QUEUE_TYPE_M     0x0000ff00
#define HTT_PPDU_STATS_FLUSH_TLV_QUEUE_TYPE_S              8

#define HTT_PPDU_STATS_FLUSH_TLV_QUEUE_TYPE_GET(_var) \
    (((_var) & HTT_PPDU_STATS_FLUSH_TLV_QUEUE_TYPE_M) >> \
    HTT_PPDU_STATS_FLUSH_TLV_QUEUE_TYPE_S)

#define HTT_PPDU_STATS_FLUSH_TLV_QUEUE_TYPE_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_FLUSH_TLV_QUEUE_TYPE, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_FLUSH_TLV_QUEUE_TYPE_S)); \
     } while (0)

#define HTT_PPDU_STATS_FLUSH_TLV_SW_PEER_ID_M     0xffff0000
#define HTT_PPDU_STATS_FLUSH_TLV_SW_PEER_ID_S             16

#define HTT_PPDU_STATS_FLUSH_TLV_SW_PEER_ID_GET(_var) \
    (((_var) & HTT_PPDU_STATS_FLUSH_TLV_SW_PEER_ID_M) >> \
    HTT_PPDU_STATS_FLUSH_TLV_SW_PEER_ID_S)

#define HTT_PPDU_STATS_FLUSH_TLV_SW_PEER_ID_SET(_var, _val) \
     do { \
         HTT_CHECK_SET_VAL(HTT_PPDU_STATS_FLUSH_TLV_SW_PEER_ID, _val); \
         ((_var) |= ((_val) << HTT_PPDU_STATS_FLUSH_TLV_SW_PEER_ID_S)); \
     } while (0)

enum HTT_TX_FLOW_TYPE {
    HTT_TX_TID_FRAMEQ,
    HTT_TX_TQM_MSDUQ,
    HTT_TQM_MPDUQ,
};

enum HTT_FLUSH_STATUS_DROP_REASON {
    HTT_FLUSH_PEER_DELETE,
    HTT_FLUSH_TID_DELETE,
    HTT_FLUSH_TTL_EXCEEDED,
    HTT_FLUSH_EXCESS_RETRIES,
    HTT_FLUSH_REINJECT,
};

typedef struct {
    htt_tlv_hdr_t tlv_hdr;

    A_UINT32 drop_reason;
    /* BIT [ 7 :   0]   :- flow_type
     * BIT [ 16:   8]   :- num_mpdu
     * BIT [ 30:  17]   :- num_msdu
     * BIT [ 31:  31]   :- reserved0
     */
    union {
        A_UINT32 num_msdu__num_mpdu__flow_type;
        struct {
            A_UINT32 flow_type:        8,
                     num_mpdu:         9,
                     num_msdu:        14,
                     reserved0:        1;
        };
    };

    /* BIT [ 7  :   0]   :- tid_num
     * BIT [ 15 :   8]   :- queue_type
     * BIT [ 31 :  16]   :- sw_peer_id
     */
    union {
        A_UINT32 sw_peer_id__queue_type__tid_num;
        struct {
            A_UINT32 tid_num:          8,
                     queue_type:       8,
                     sw_peer_id:       16;
        };
    };
} htt_ppdu_stats_flush_tlv;

typedef struct {
    htt_tlv_hdr_t tlv_hdr;

    /* Future purpose */
    A_UINT32 reserved1; /* set to 0x0 */
    A_UINT32 reserved2; /* set to 0x0 */
    A_UINT32 reserved3; /* set to 0x0 */

    /* mgmt/ctrl frame payload
     * The size of payload (in bytes) can be derived from the length in
     * tlv parametes, minus the 12 bytes of the above fields.
     */
    A_UINT32 payload[1];
} htt_ppdu_stats_tx_mgmtctrl_payload_tlv;


#endif //__HTT_PPDU_STATS_H__
