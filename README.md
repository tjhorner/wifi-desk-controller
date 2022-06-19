# WiFi Desk Controller

This repository includes the source files for my WiFi Desk Controller design.

- `firmware`: The stock ESPHome-based firmware that's available from the GitHub Releases and [my website](https://shop.horner.tj/things/desk-controller/setup/stock)
- `enclosure`: Fusion 360 source, STL, and STEP files for the 3D-printable enclosure
- `pcb`: KiCad project files for the PCB

You may also find the associated [ESPHome custom component](https://github.com/tjhorner/esphome-standing-desk) interesting if you want to implement your own desk brand, or just dive deeper into how the firmware works.

## Stock Firmware

The stock firmware is automatically built for each supported desk on release. There is a [GitHub Actions workflow](.github/workflows/build.yaml) which handles this. The `make-stock-bin` script replaces the `DESK_BRAND` in the [stock config.yaml](firmware/config.yaml) with the appropriate config and builds it. It runs this script for each of the supported desk brands in the build matrix, then uploads a release artifact.

If you would like to contribute compatibility for a new desk, you first need to submit a pull request to [this repo](https://github.com/tjhorner/esphome-standing-desk/tree/master/configs/desks) which adds a config file for the desk (and, if necessary, a new protocol decoder for it). See [Desk Compatibility](https://github.com/tjhorner/wifi-desk-controller/wiki/Desk-Compatibility) for more info on adding a new desk brand.

## License

The ESPHome configs are licensed under MIT; everything else (enclosure and PCB design) are CC BY-NC-SA 4.0. The appropriate license files are available in the root of the repo.
