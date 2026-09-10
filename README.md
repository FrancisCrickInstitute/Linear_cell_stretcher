## Linear cell stretcher

<img width="1280" height="720" alt="Slide2" src="https://github.com/user-attachments/assets/79189271-25b0-4073-b7c5-f6121c4fdc41" />

### Bill of Materials (BOM)

| Name | Quantity | Link |
| :--- | :---: | :--- |
| Linear stepper motor stage | 1 | [Stepper online](https://www.stepperonline.co.uk/nema-14-stepper-ball-screw-linear-actuator-1-5a-stroke-40mm-0-2nm-28-32oz-in-lead-2mm-0-0787-with-sensor-lmd14s18bab15-040.html) |
| Teensy 4.0 | 1 | [PiHut](https://thepihut.com/products/teensy-4-0-headers?srsltid=AfmBOopdxw6T2mRoe89vy1RnNPfoABqAtgEuZ_HuxT9B1b6C_WVSnCzA) |
| Stepper motor driver | 1 | [Amazon](https://www.amazon.co.uk/dp/B07XRF8YPX?ref=fed_asin_title) |
| M2 threaded inserts | 4 | [Amazon](https://www.amazon.co.uk/dp/B0DFBVLHH7?ref=fed_asin_title&th=1) |
| M3 threaded inserts | 4 | [Amazon](https://www.amazon.co.uk/dp/B0DFBTB5LN?ref=fed_asin_title&th=1) |
| 5 mm rods (For the stretcher)| 1 | [Amazon](https://www.amazon.co.uk/dp/B0FHK1SYZM?ref=fed_asin_title&th=1) |
| 5.2 mm rods (For the mould)| 1 | [Amazon](https://www.amazon.co.uk/dp/B0DYT6DDYS?ref=fed_asin_title&th=1) |
| 12V AD/DC power adapter | 1 | [Amazon](https://www.amazon.co.uk/Adapter-100-240V-Transformer-Charger-Cameras/dp/B0FJ5NYKD2/ref=sr_1_1_sspa?crid=6YTZ6LN7BSLS&dib=eyJ2IjoiMSJ9.9Byisz9i4tH97dhDhpzTIwfUvVsrxEJx1myTcrUXhjZWyJhMo7WOqak-2_bwfGS2KHJMIW5Ge3JxD97DEQkpPA9al5dujPYnE6-y4aAbSjaDOE4lSm2NYjVMXxVcQAYVCgJsE5MpsLZQFchw1YstizjceF8Uo9wWck6duFo6MveHvSz-ALDMLNQBBWGwmmPpbwRwQOv40WAXng01IAQz-IC5ZVwLUXqttM_IHh7iJWA.zrYlMtvUruTa96Vh3CkU1JSdsLA8yGTd_5ngZqkeAAQ&dib_tag=se&keywords=12v%2Bac%2Fdc%2Bpower%2Badapter%2B3A&qid=1786965498&sprefix=12v%2Bac%2Fdc%2Bpower%2Badapter%2B3a%2Caps%2C167&sr=8-1-spons&aref=55OFwy3Fm4&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&th=1) |
| M3 x 50 mm button screws | 2 | [Accu](https://www.accu.co.uk/socket-button-screws/8115-SSB-M3-50-A2) |
| RJ45 patch cable | 1 | [Amazon]() |
| M2 screws | 4 | [Accu]() |
| M3 screws | 10 | [Accu]() |



### Assembly instructions

- 3D print the components using more than 50% infill settings and PLA as material
- Laser cut the two-part lid cover
- Insert M2 threaded inserts on the bottom sides of the 3D printed parts: puller and the enclosure base
- Solder the Control PCB components

- Cut to the right length and solder the optical homing sensor cable and the stepper motor cable with the linear stepper connection board
<img width="1420" height="590" alt="image" src="https://github.com/user-attachments/assets/a39745a1-9c80-46ca-93bc-047721532de1" />


- Attach the linear stepper connection board at the back of the motor with the 3D printed spacer in between removing two of the original stepper motor screws and replacing them by two 50 mm M3 screws.
<img width="796" height="416" alt="image" src="https://github.com/user-attachments/assets/1555c116-4972-447d-81b8-615ea42dfa9f" />

- Place four M3 inserts in the enclosure base and lid holes
- Glue the big part of the lid cover on top of the 3D printed enclosure lid. The front smaller lid is not glued as it is removable to be able to access the wells with the pipette

- Change the position of the homing sensor using the front side M3 tapped holes
<img width="800" height="450" alt="image" src="https://github.com/user-attachments/assets/16f881c6-4adf-4f81-81e0-fad2cabbddc9" />

- Attach the 3D printed beam breaker on the carriage using two M3 screws
<img width="800" height="450" alt="image" src="https://github.com/user-attachments/assets/fed7b0b4-8fb3-497a-99eb-c4a5276316fd" />

- Attach the 3D printed puller on top of the linear stage carriage using 4 M3 screws
<img width="800" height="450" alt="image" src="https://github.com/user-attachments/assets/f9868834-e6db-4ef2-8919-45641fc4382e" />

- Attach the linear stage with the enclosure base (3D printed) using four M3 screws
<img width="800" height="450" alt="image" src="https://github.com/user-attachments/assets/a0deb7cf-adf3-4c3f-bb51-e8a70bd0439a" />

- The 5 mm bars are held using 2 M2 screws in both the puller and the 3D printed enclosure
<img width="800" height="450" alt="image" src="https://github.com/user-attachments/assets/c11f1a95-af83-4d85-bf49-a08f01d84a8e" />

- Grab the optical sensor cable through the two cable guides
- <img width="950" height="461" alt="image" src="https://github.com/user-attachments/assets/42f383da-cc16-464b-b19f-9821828b1acf" />

- Place 4 grub screws into the enclosure lid holes and place the lid on top of the enclosure base
<img width="800" height="450" alt="image" src="https://github.com/user-attachments/assets/93f9021d-d1bc-46fb-b2ff-f8e23f0bdd23" />

- Upload the firmware on the Teensy 4

- Conenct the device and the control board using a RJ45 cable

- Connect the 12V, 36W power supply in the control board barrel jack connector
<img width="1374" height="696" alt="image" src="https://github.com/user-attachments/assets/36a613b7-5820-4dbb-8ab1-31f330f3e6c6" />

- Select the frequency (0.05 - 1 Hz) and stretch length (using the stretch and frequancy knobs) and mode (pressing the stretch knob) 

- Press the frequency knob to change the state of the device to active and it will start pulling, if pressed and held again it will stop at the end of the cycle

- Place the PDMS wells in the rods
<img width="762" height="518" alt="image" src="https://github.com/user-attachments/assets/d8207e16-ea7f-4ab7-a874-6ae795c77a1a" />


#### Modes:
- Cyclic stretch
- Cyclic stretch holding for a defined period of time (specified in the firmware)
- Stretch and hold


### PDMS mould casting process

The moulds for creating the wells have been 3D printed using Formlabs clear V5 resin in a Form 4 3D printer. After IPA washing (15 min) and UV curing (60 degC for 1h on the Formlabs Form cure) they have been baked in the oven at 75 degC for 4h to ensure a completely crosslinked structure. Then 1:10 PDMS ratio has been poured and cured at 65 degC for 4h. Then the 5.2 mm rods can be removed and the PDMS wells carefully peeled off using a flat thin spatula.

<img width="1386" height="646" alt="image" src="https://github.com/user-attachments/assets/a2183dd7-f9f1-4db1-ae2a-39e309a966d6" />

