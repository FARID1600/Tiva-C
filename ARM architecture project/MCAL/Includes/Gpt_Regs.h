/**************************************************************************************************************
 *
 *   Module --> General Purpose Timer
 *
 *   File name --> Gpt_Regs.h
 *
 *   Description --> Registers assignment for TM4C123GH6PM Microcontroller - General Purpose Timer Driver.
 *
 *   Author --> Abdelrahman Farid
 *
**************************************************************************************************************/

#ifndef GPT_REGS_H
#define GPT_REGS_H

/*******************************************   TIMERS BASE ADDRESS --> PAGE 725   *******************************************/

// The best way to access the timers base address:
#define GPT_BASE_OFFSET(num)            ( (num < 8)? ( (0x40030000) + ( (0x1000) * num ) ) : ( (0x4004C000) + ( (0x1000) * (8 - num) ) ) )

/*******************************************   TIMERS REGISTER MAP --> PAGE 726   *******************************************/

#define GPTMCFG(num)                ( *(volatile uint32*)( GPT_BASE_OFFSET(num) + 0x000) )
#define GPTMTAMR(num)               ( *(volatile uint32*)(GPT_BASE_OFFSET(num)  + 0x004) )
#define GPTMTBMR(num)               ( *(volatile uint32*)(GPT_BASE_OFFSET(num)  + 0x008) )
#define GPTMCTL(num)                ( *(volatile uint32*)(GPT_BASE_OFFSET(num)  + 0x00C) )
#define GPTMSYNC(num)               ( *(volatile uint32*)(GPT_BASE_OFFSET(num)  + 0x010) )
#define GPTMIMR(num)                ( *(volatile uint32*)(GPT_BASE_OFFSET(num)  + 0x018) )
#define GPTMRIS(num)                ( *(volatile uint32*)(GPT_BASE_OFFSET(num)  + 0x01C) )
#define GPTMMIS(num)                ( *(volatile uint32*)(GPT_BASE_OFFSET(num)  + 0x020) )
#define GPTMICR(num)                ( *(volatile uint32*)(GPT_BASE_OFFSET(num)  + 0x024) )
#define GPTMTAILR(num)              ( *(volatile uint32*)(GPT_BASE_OFFSET(num)  + 0x028) )
#define GPTMTBILR(num)              ( *(volatile uint32*)(GPT_BASE_OFFSET(num)  + 0x02C) )
#define GPTMTAMATCHR(num)           ( *(volatile uint32*)(GPT_BASE_OFFSET(num)  + 0x030) )
#define GPTMTBMATCHR(num)           ( *(volatile uint32*)(GPT_BASE_OFFSET(num)  + 0x034) )
#define GPTMTAPR(num)               ( *(volatile uint32*)(GPT_BASE_OFFSET(num)  + 0x038) )
#define GPTMTBPR(num)               ( *(volatile uint32*)(GPT_BASE_OFFSET(num)  + 0x03C) )
#define GPTMTAPMR(num)              ( *(volatile uint32*)(GPT_BASE_OFFSET(num)  + 0x040) )
#define GPTMTBPMR(num)              ( *(volatile uint32*)(GPT_BASE_OFFSET(num)  + 0x044) )
#define GPTMTAR(num)                ( *(volatile uint32*)(GPT_BASE_OFFSET(num)  + 0x048) )
#define GPTMTBR(num)                ( *(volatile uint32*)(GPT_BASE_OFFSET(num)  + 0x04C) )
#define GPTMTAV(num)                ( *(volatile uint32*)(GPT_BASE_OFFSET(num)  + 0x050) )
#define GPTMTBV(num)                ( *(volatile uint32*)(GPT_BASE_OFFSET(num)  + 0x054) )
#define GPTMRTCPD(num)              ( *(volatile uint32*)(GPT_BASE_OFFSET(num)  + 0x058) )
#define GPTMTAPS(num)               ( *(volatile uint32*)(GPT_BASE_OFFSET(num)  + 0x05C) )
#define GPTMTBPS(num)               ( *(volatile uint32*)(GPT_BASE_OFFSET(num)  + 0x060) )
#define GPTMTAPV(num)               ( *(volatile uint32*)(GPT_BASE_OFFSET(num)  + 0x064) )
#define GPTMTBPV(num)               ( *(volatile uint32*)(GPT_BASE_OFFSET(num)  + 0x068) )
#define GPTMPP(num)                 ( *(volatile uint32*)(GPT_BASE_OFFSET(num)  + 0xFC0) )
// The best way to access the RCGC register:
#define RCGC(x)	                    ( *( (volatile uint32*)( x<6? 0x400FE604 : 0x400FE65C ) ) )

/*******************************************   TIMERS REGISTER MASKS   *******************************************/
#define GPTMCTL_TAEN_MASK           0x00000000
#define GPTMCTL_TASTALL_MASK        0x00000001
#define GPTMTAMR_TACDIR_MASK        0x00000010
#define GPTMTAMR_TAMIE_MASK         0x00000020
#define GPTMTAMR_TAWOT_MASK         0x00000040
#define GPTMICR_TATOCINT_MASK       0x00000000
#define GPTMIMR_TATOIM_MASK		    0x00000000

#endif