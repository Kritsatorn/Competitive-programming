from my_project import find_mcu_boards, McuBoard, PeriBoard
from time import sleep

devs = find_mcu_boards()

if len(devs) == 0:
    print("*** No practicum board found.")
    exit(1)

mcu = McuBoard(devs[0])
print("*** Practicum board found")
print("*** Manufacturer: %s" % \
        mcu.handle.getString(mcu.device.iManufacturer, 256))
print("*** Product: %s" % \
        mcu.handle.getString(mcu.device.iProduct, 256))
peri = PeriBoard(mcu)

count = 0
while True:

    light1 = peri.get_light1()
    light2 = peri.get_light2()

    print("LEDs set to %d |  Light1 value: %d | Light2 value: %d" % (
            count, light1, light2))

    count = (count + 1) % 8
    sleep(0.5)