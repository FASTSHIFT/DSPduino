################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Core/28035_source/DSP2803x_common/source/%.obj: ../Core/28035_source/DSP2803x_common/source/%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs910/ccs/tools/compiler/ti-cgt-c2000_18.12.2.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 -O4 --opt_for_speed=0 --include_path="G:/DESIGN/DSP_Project/_DSPduino(TMS320F28035)" --include_path="G:/DESIGN/DSP_Project/_DSPduino(TMS320F28035)/Libraries" --include_path="G:/DESIGN/DSP_Project/_DSPduino(TMS320F28035)/ArduinoAPI" --include_path="G:/DESIGN/DSP_Project/_DSPduino(TMS320F28035)/Core" --include_path="G:/DESIGN/DSP_Project/_DSPduino(TMS320F28035)/Core/28035_source/DSP2803x_common/include" --include_path="G:/DESIGN/DSP_Project/_DSPduino(TMS320F28035)/Core/28035_source/DSP2803x_headers/include" --include_path="C:/ti/ccs910/ccs/tools/compiler/ti-cgt-c2000_18.12.2.LTS/include" --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="Core/28035_source/DSP2803x_common/source/$(basename $(<F)).d_raw" --obj_directory="Core/28035_source/DSP2803x_common/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Core/28035_source/DSP2803x_common/source/%.obj: ../Core/28035_source/DSP2803x_common/source/%.asm $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs910/ccs/tools/compiler/ti-cgt-c2000_18.12.2.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 -O4 --opt_for_speed=0 --include_path="G:/DESIGN/DSP_Project/_DSPduino(TMS320F28035)" --include_path="G:/DESIGN/DSP_Project/_DSPduino(TMS320F28035)/Libraries" --include_path="G:/DESIGN/DSP_Project/_DSPduino(TMS320F28035)/ArduinoAPI" --include_path="G:/DESIGN/DSP_Project/_DSPduino(TMS320F28035)/Core" --include_path="G:/DESIGN/DSP_Project/_DSPduino(TMS320F28035)/Core/28035_source/DSP2803x_common/include" --include_path="G:/DESIGN/DSP_Project/_DSPduino(TMS320F28035)/Core/28035_source/DSP2803x_headers/include" --include_path="C:/ti/ccs910/ccs/tools/compiler/ti-cgt-c2000_18.12.2.LTS/include" --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="Core/28035_source/DSP2803x_common/source/$(basename $(<F)).d_raw" --obj_directory="Core/28035_source/DSP2803x_common/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


