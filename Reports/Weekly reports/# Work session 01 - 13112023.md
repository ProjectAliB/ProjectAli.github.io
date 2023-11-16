# Work session 01 - 13/11/2023

## Overview

My work this session was mainly focused on finding the right motor that fulfills our need for the vehicle.

## Documentation

Our aim is to build a vehicle that respects the following criteria:
- Light-wheighted
- Speed reaching 45km/h
- Cheap and affordable
- Simple to assemble
- Long cycle of life
- Energy efficient

Having an motor adapted to those needs is therefore neccessary. Out of the many suppliers and manufactures of motors, we limited our options to the following ones:
- [Ozo ](https://ozo-electric.com/fr/moteurs-roues-arrieres-250w-a-2000w/991015-moteur-dd35-transport-arriere-direct-drive-2000w.html?gad=1&gclid=CjwKCAjwnOipBhBQEiwACyGLupaiiqUv1nvdlxuSrhHlcbfkGgtNHqtMXpbqWnkvk-MyLw45m2KDmRoCTY8QAvD_BwE)
- [AliExpress ](https://fr.aliexpress.com/item/1005004625728818.html?spm=a2g0o.productlist.main.39.6c342f94mJIKzf&algo_pvid=0215cd14-527f-45d2-bca1-44403d7ad1d7&aem_p4p_detail=2023110902075111470336528411980002615035&algo_exp_id=0215cd14-527f-45d2-bca1-44403d7ad1d7-19&pdp_npi=4%40dis%21EUR%21245.43%21147.26%21%21%21256.81%21%21%40211b801816995244716006927e1472%2112000029882032309%21sea%21FR%210%21AB&curPageLogUid=aiUHFNCDjycq&search_p4p_id=2023110902075111470336528411980002615035_20)
- [CDiscount ](https://www.cdiscount.com/le-sport/velos-tandem-tricycle-monocycle-remorque-casque/ashata-moteur-de-moyeu-de-roue-de-14-po-36v-72v-20/f-121192408-ash1690390599089.html?cid=search_pla&cm_mmc=PLA!COR!!MP!17321694237!m144806551_pASH1690390599089-2775757164_l9054956_tpla-294682000766__a137602897192&gad_source=1&gclid=CjwKCAjwnOipBhBQEiwACyGLusDbxZYZkvLJ9K9XQ2MvsQuEnxkECw9lO48V_z5DVupaBjEnsB-ZjRoCnigQAvD_BwE)

AS the three motors share nearly the same specifics, after a careful consideration of the product's price, delivering fees, and the possibility to contact the manufacturer when needed, we chose the Ozo product:
![Ozo hub motor](https://ozo-electric.com/6186289-thickbox_default/moteur-dd35-transport-arriere-direct-drive-2000w.jpg)
![Motor's dimensions(mm)](http://ozo-electric.com/img/cms/moteurs/DD35/plan-moteur-transport-DD35.jpg)
![Technical sheet](https://github.com/ProjectAliB/ProjectAli.github.io/blob/6aa0f8a2c6f2a623c455a85c08af97641e0e3abf/Ressources/Images%26Pictures/Screenshot%202023.png.png)

## Motor test

As it is my first time using a brushless motor, i tried using one and making it run at a certain speed. The used code was as follows :
  ## Motor test

As it is my first time using a brushless motor, i tried using one and making it run at a certain speed. The used code was as follows :
    const int moteur=5;
    void setup(){
      pinMode(moteur,OUTPUT);
      Serial.begin(9600);
    }
    void loop(){
      digitalWrite(moteur,0);
      digitalRead(moteur);
      delay(5000);
      digitalWrite(moteur,1);
      digitalRead(moteur);
    }
Carefully connecting each wire into its suitable pin, there was no apparent mistake in the installation.

The motor however still didn't seem to be working, although it was alimented by 12V. The problem may reside ine the code.
