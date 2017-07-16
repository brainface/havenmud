/*  A player run inn */
#include <lib.h>
inherit LIB_PLAYER_SHOP;

static void create() {
  player_shop::create();
    SetShopId("argoth_inn");
  SetDomain("Crystal Reaches");
  SetExits( ([
    "out" : "/domains/crystal_reaches/towns/argoth/room/rd5.c",
    ]) );
    SetTown("Argoth");
    SetLocalCurrency("khuca");
  }
