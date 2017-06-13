Torcs Handbook
=====
This file descrips some common torcs usages for _version=1.3.7_.

**Installation**
```shell
cd torcs-1.3.7
./configure
make -j4
sudo make install
sudo make datainstall
```

**Unistall**
```shell
sudo rm -fr /usr/local/bin/torcs
sudo rm -fr /usr/local/lib/torcs
sudo rm -fr /usr/local/share/games/torcs
```

**Generate a robot**  
First check the car types:
```shell
$ ls /usr/local/share/games/torcs/cars
# results:
155-DTM       car2-trb1  kc-a110           kc-dbs        pw-206wrc
acura-nsx-sz  car3-trb1  kc-alfatz2        kc-dino       pw-306wrc
baja-bug      car4-trb1  kc-bigh           kc-ghibli     pw-corollawrc
buggy         car5-trb1  kc-cobra          kc-giulietta  pw-evoviwrc
car1-ow1      car6-trb1  kc-coda           kc-grifo      pw-focuswrc
car1-stock1   car7-trb1  kc-conrero        kc-gt40       pw-imprezawrc
car1-stock2   car8-trb1  kc-corvette-ttop  kc-gto
car1-trb1     kc-2000gt  kc-daytona        kc-p4
car1-trb3     kc-5300gt  kc-db4z           p406
```
Go to TORCS_BASE and generate a bot.
```shell
$ cd torcs-1.3.7
$ ./robotgen -n "drl_bot" -a "lidong" -c "car1-trb1" --gpl
Generation of robot drl_bot author lidong
Copying car1-trb1.rgb ... and car1-trb1.xcf ... done
Copying logo.rgb ... done
Generating src/drivers/drl_bot/Makefile ... done
Generating src/drivers/drl_bot/drl_bot.xml ... done
Generating src/drivers/drl_bot/drl_bot.cpp ... done
Generating src/drivers/drl_bot/drl_bot.def ... done
Generating src/drivers/drl_bot/drl_bot.dsp ... done
```
