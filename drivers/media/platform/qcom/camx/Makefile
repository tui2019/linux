# SPDX-License-Identifier: GPL-2.0-only
#
# Qualcomm Spectra Camera (CamX camera_kt) in-tree build for SM7125 (SM-P613)
#

CAMX_SRC := $(src)

ccflags-y += \
	-DCONFIG_QCM6490=1 \
	-I$(CAMX_SRC)/camera_kt/include/uapi/camera/media \
	-I$(CAMX_SRC)/camera_kt/include/uapi/camera \
	-I$(CAMX_SRC)/camera_kt/include/uapi \
	-I$(CAMX_SRC)/camera_kt \
	-I$(CAMX_SRC) \
	-I$(CAMX_SRC)/common \
	-I$(CAMX_SRC)/camera_kt/drivers \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_jpeg \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_jpeg/jpeg_hw/include \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_jpeg/jpeg_hw/jpeg_enc_hw \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_jpeg/jpeg_hw/jpeg_dma_hw \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_cdm \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_sensor_module/cam_eeprom \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_sensor_module/cam_sensor_io \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_sensor_module/cam_sensor \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_sensor_module/cam_res_mgr \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_sensor_module/cam_hdmi_bdg \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_sensor_module/cam_ois \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_sensor_module/cam_csiphy \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_sensor_module/cam_csiphy/include \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_sensor_module/cam_ir_led \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_sensor_module/cam_lens_driver \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_sensor_module/cam_flash \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_sensor_module/cam_cci \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_sensor_module/cam_cci/include \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_sensor_module/cam_dp_bdg \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_sensor_module/cam_actuator \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_sensor_module/cam_sensor_utils \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_sensor_module/cam_tpg \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_sensor_module/cam_tpg/tpg_hw \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_sensor_module/cam_tpg/tpg_hw/tpg_hw_v_1_0 \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_sensor_module/cam_tpg/tpg_hw/tpg_hw_v_1_2 \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_sensor_module/cam_tpg/tpg_hw/tpg_hw_v_1_3 \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_sensor_module/cam_tpg/tpg_hw/tpg_hw_v_1_4 \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_cust \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_cust/cam_custom_hw_mgr \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_cust/cam_custom_hw_mgr/include \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_cust/cam_custom_hw_mgr/cam_custom_hw1 \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_cust/cam_custom_hw_mgr/cam_custom_csid \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_ope \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_ope/ope_hw_mgr \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_ope/ope_hw_mgr/ope_hw \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_icp \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_icp/fw_inc \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_icp/icp_hw/include \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_icp/icp_hw/icp_hw_mgr/include \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_icp/icp_hw/icp_hw_mgr \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_icp/icp_hw/a5_hw \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_icp/icp_hw/bps_hw \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_icp/icp_hw/ipe_hw \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_icp/icp_hw/ofe_hw \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_lrme \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_lrme/lrme_hw_mgr \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_lrme/lrme_hw_mgr/lrme_hw \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_core \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_cpas \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_cpas/include \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_cpas/cpas_top \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_cpas/camss_top \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_req_mgr \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_utils \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_smmu \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_sync \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_fd \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_fd/fd_hw_mgr \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_fd/fd_hw_mgr/fd_hw \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_isp \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_isp/isp_hw_mgr \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_isp/isp_hw_mgr/include \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_isp/isp_hw_mgr/hw_utils \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_isp/isp_hw_mgr/hw_utils/include \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_isp/isp_hw_mgr/hw_utils/irq_controller \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/include \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/vfe_hw \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/vfe_hw/vfe_top \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/vfe_hw/vfe_top/include \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/vfe_hw/vfe_bus \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/vfe_hw/vfe_bus/include \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/vfe_hw/vfe17x \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/ife_csid_hw \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/tfe_hw \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/tfe_csid_hw \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/sfe_hw \
	-I$(CAMX_SRC)/camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/top_tpg

CFLAGS_camera_kt/drivers/cam_utils/cam_trace.o := -I$(CAMX_SRC)/camera_kt/drivers/cam_utils

obj-$(CONFIG_SPECTRA_CAMERA) += spectra_camx.o

spectra_camx-y := \
	camera_kt/drivers/cam_req_mgr/cam_req_mgr_core.o \
	camera_kt/drivers/cam_req_mgr/cam_req_mgr_dev.o \
	camera_kt/drivers/cam_req_mgr/cam_req_mgr_debug.o \
	camera_kt/drivers/cam_utils/cam_soc_util.o \
	camera_kt/drivers/cam_utils/cam_packet_util.o \
	camera_kt/drivers/cam_utils/cam_trace.o \
	camera_kt/drivers/cam_core/cam_context.o \
	camera_kt/drivers/cam_core/cam_context_utils.o \
	camera_kt/drivers/cam_core/cam_node.o \
	camera_kt/drivers/cam_core/cam_subdev.o \
	camera_kt/drivers/cam_sync/cam_sync.o \
	camera_kt/drivers/cam_sync/cam_sync_util.o \
	camera_kt/drivers/cam_cpas/cpas_top/cam_cpastop_hw.o \
	camera_kt/drivers/cam_cpas/camss_top/cam_camsstop_hw.o \
	camera_kt/drivers/cam_cpas/cam_cpas_soc.o \
	camera_kt/drivers/cam_cpas/cam_cpas_intf.o \
	camera_kt/drivers/cam_cpas/cam_cpas_hw.o \
	camera_kt/drivers/cam_cdm/cam_cdm_soc.o \
	camera_kt/drivers/cam_cdm/cam_cdm_util.o \
	camera_kt/drivers/cam_cdm/cam_cdm_intf.o \
	camera_kt/drivers/cam_cdm/cam_cdm_core_common.o \
	camera_kt/drivers/cam_cdm/cam_cdm_virtual_core.o \
	camera_kt/drivers/cam_cdm/cam_cdm_hw_core.o \
	camera_kt/drivers/cam_req_mgr/cam_mem_mgr.o \
	camera_kt/drivers/cam_smmu/cam_smmu_api.o \
	common/cam_common_util.o \
	common/cam_icp_util.o \
	common/cam_compat.o \
	common/cam_debug_util.o \
	common/cam_io_util.o \
	common/cam_req_mgr_timer.o \
	common/cam_req_mgr_util.o \
	common/cam_req_mgr_workq.o \
	common/cam_soc_icc.o

spectra_camx-$(CONFIG_ENABLE_US_API) += \
	camera_kt/drivers/cam_req_mgr/cam_buf_mgr.o

spectra_camx-$(CONFIG_SPECTRA_ISP) += \
	camera_kt/drivers/cam_isp/isp_hw_mgr/hw_utils/cam_tasklet_util.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/hw_utils/cam_isp_packet_parser.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/hw_utils/irq_controller/cam_irq_controller.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/ife_csid_hw/cam_ife_csid_dev.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/ife_csid_hw/cam_ife_csid_soc.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/ife_csid_hw/cam_ife_csid17x.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/ife_csid_hw/cam_ife_csid_lite17x.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/ife_csid_hw/cam_ife_csid_core.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/vfe_hw/cam_vfe_soc.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/vfe_hw/cam_vfe_dev.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/vfe_hw/cam_vfe_core.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/vfe_hw/vfe_bus/cam_vfe_bus.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/vfe_hw/vfe_bus/cam_vfe_bus_ver2.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/vfe_hw/vfe_bus/cam_vfe_bus_rd_ver1.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/vfe_hw/vfe_bus/cam_vfe_bus_ver3.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/vfe_hw/vfe_top/cam_vfe_camif_lite_ver2.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/vfe_hw/vfe_top/cam_vfe_top.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/vfe_hw/vfe_top/cam_vfe_top_common.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/vfe_hw/vfe_top/cam_vfe_top_ver3.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/vfe_hw/vfe_top/cam_vfe_top_ver2.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/vfe_hw/vfe_top/cam_vfe_camif_ver2.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/vfe_hw/vfe_top/cam_vfe_camif_ver3.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/vfe_hw/vfe_top/cam_vfe_rdi.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/vfe_hw/vfe_top/cam_vfe_fe_ver1.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/vfe_hw/vfe_top/cam_vfe_camif_lite_ver3.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/vfe_hw/vfe17x/cam_vfe.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/cam_isp_hw_mgr.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/cam_ife_hw_mgr.o \
	camera_kt/drivers/cam_isp/cam_isp_dev.o \
	camera_kt/drivers/cam_isp/cam_isp_context.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/top_tpg/cam_top_tpg_ver2.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/top_tpg/cam_top_tpg_soc.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/top_tpg/cam_top_tpg_core.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/top_tpg/cam_top_tpg_ver3.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/top_tpg/cam_top_tpg_dev.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/top_tpg/cam_top_tpg.o \
	camera_kt/drivers/cam_isp/isp_hw_mgr/isp_hw/top_tpg/cam_top_tpg_ver1.o

spectra_camx-$(CONFIG_SPECTRA_ICP) += \
	camera_kt/drivers/cam_icp/icp_hw/icp_hw_mgr/cam_icp_hw_mgr.o \
	camera_kt/drivers/cam_icp/icp_hw/ipe_hw/ipe_dev.o \
	camera_kt/drivers/cam_icp/icp_hw/ipe_hw/ipe_core.o \
	camera_kt/drivers/cam_icp/icp_hw/ipe_hw/ipe_soc.o \
	camera_kt/drivers/cam_icp/icp_hw/a5_hw/a5_dev.o \
	camera_kt/drivers/cam_icp/icp_hw/a5_hw/a5_core.o \
	camera_kt/drivers/cam_icp/icp_hw/a5_hw/a5_soc.o \
	camera_kt/drivers/cam_icp/icp_hw/bps_hw/bps_dev.o \
	camera_kt/drivers/cam_icp/icp_hw/bps_hw/bps_core.o \
	camera_kt/drivers/cam_icp/icp_hw/bps_hw/bps_soc.o \
	camera_kt/drivers/cam_icp/cam_icp_subdev.o \
	camera_kt/drivers/cam_icp/cam_icp_context.o \
	camera_kt/drivers/cam_icp/hfi.o

spectra_camx-$(CONFIG_SPECTRA_JPEG) += \
	camera_kt/drivers/cam_jpeg/jpeg_hw/jpeg_enc_hw/jpeg_enc_dev.o \
	camera_kt/drivers/cam_jpeg/jpeg_hw/jpeg_enc_hw/jpeg_enc_core.o \
	camera_kt/drivers/cam_jpeg/jpeg_hw/jpeg_enc_hw/jpeg_enc_soc.o \
	camera_kt/drivers/cam_jpeg/jpeg_hw/jpeg_dma_hw/jpeg_dma_dev.o \
	camera_kt/drivers/cam_jpeg/jpeg_hw/jpeg_dma_hw/jpeg_dma_core.o \
	camera_kt/drivers/cam_jpeg/jpeg_hw/jpeg_dma_hw/jpeg_dma_soc.o \
	camera_kt/drivers/cam_jpeg/jpeg_hw/cam_jpeg_hw_mgr.o \
	camera_kt/drivers/cam_jpeg/cam_jpeg_dev.o \
	camera_kt/drivers/cam_jpeg/cam_jpeg_context.o

spectra_camx-$(CONFIG_SPECTRA_LRME) += \
	camera_kt/drivers/cam_lrme/lrme_hw_mgr/lrme_hw/cam_lrme_hw_dev.o \
	camera_kt/drivers/cam_lrme/lrme_hw_mgr/lrme_hw/cam_lrme_hw_core.o \
	camera_kt/drivers/cam_lrme/lrme_hw_mgr/lrme_hw/cam_lrme_hw_soc.o \
	camera_kt/drivers/cam_lrme/lrme_hw_mgr/cam_lrme_hw_mgr.o \
	camera_kt/drivers/cam_lrme/cam_lrme_dev.o \
	camera_kt/drivers/cam_lrme/cam_lrme_context.o

spectra_camx-$(CONFIG_SPECTRA_SENSOR) += \
	camera_kt/drivers/cam_sensor_module/cam_actuator/cam_actuator_dev.o \
	camera_kt/drivers/cam_sensor_module/cam_actuator/cam_actuator_core.o \
	camera_kt/drivers/cam_sensor_module/cam_actuator/cam_actuator_soc.o \
	camera_kt/drivers/cam_sensor_module/cam_cci/cam_cci_dev.o \
	camera_kt/drivers/cam_sensor_module/cam_cci/cam_cci_core.o \
	camera_kt/drivers/cam_sensor_module/cam_cci/cam_cci_soc.o \
	camera_kt/drivers/cam_sensor_module/cam_csiphy/cam_csiphy_soc.o \
	camera_kt/drivers/cam_sensor_module/cam_csiphy/cam_csiphy_dev.o \
	camera_kt/drivers/cam_sensor_module/cam_csiphy/cam_csiphy_core.o \
	camera_kt/drivers/cam_sensor_module/cam_eeprom/cam_eeprom_dev.o \
	camera_kt/drivers/cam_sensor_module/cam_eeprom/cam_eeprom_core.o \
	camera_kt/drivers/cam_sensor_module/cam_eeprom/cam_eeprom_soc.o \
	camera_kt/drivers/cam_sensor_module/cam_ois/cam_ois_dev.o \
	camera_kt/drivers/cam_sensor_module/cam_ois/cam_ois_core.o \
	camera_kt/drivers/cam_sensor_module/cam_ois/cam_ois_soc.o \
	camera_kt/drivers/cam_sensor_module/cam_sensor/cam_sensor_dev.o \
	camera_kt/drivers/cam_sensor_module/cam_sensor/cam_sensor_core.o \
	camera_kt/drivers/cam_sensor_module/cam_sensor/cam_sensor_soc.o \
	camera_kt/drivers/cam_sensor_module/cam_sensor_io/cam_sensor_io.o \
	camera_kt/drivers/cam_sensor_module/cam_sensor_io/cam_sensor_cci_i2c.o \
	camera_kt/drivers/cam_sensor_module/cam_sensor_io/cam_sensor_qup_i2c.o \
	camera_kt/drivers/cam_sensor_module/cam_sensor_io/cam_sensor_spi.o \
	camera_kt/drivers/cam_sensor_module/cam_sensor_utils/cam_sensor_util.o \
	camera_kt/drivers/cam_sensor_module/cam_res_mgr/cam_res_mgr.o \
	camera_kt/drivers/cam_sensor_module/cam_flash/cam_flash_dev.o \
	camera_kt/drivers/cam_sensor_module/cam_flash/cam_flash_core.o \
	camera_kt/drivers/cam_sensor_module/cam_flash/cam_flash_soc.o \
	camera_kt/drivers/cam_sensor_module/cam_dp_bdg/cam_dp_bdg_dev.o \
	camera_kt/drivers/cam_sensor_module/cam_dp_bdg/cam_dp_bdg_core.o \
	camera_kt/drivers/cam_sensor_module/cam_hdmi_bdg/cam_hdmi_bdg_dev.o \
	camera_kt/drivers/cam_sensor_module/cam_hdmi_bdg/cam_hdmi_bdg_core.o \
	camera_kt/drivers/cam_sensor_module/cam_ir_led/cam_ir_led_dev.o \
	camera_kt/drivers/cam_sensor_module/cam_ir_led/cam_ir_led_core.o \
	camera_kt/drivers/cam_sensor_module/cam_ir_led/cam_ir_led_soc.o \
	camera_kt/drivers/cam_sensor_module/cam_lens_driver/cam_lens_driver_dev.o \
	camera_kt/drivers/cam_sensor_module/cam_lens_driver/cam_lens_driver_core.o \
	camera_kt/drivers/cam_sensor_module/cam_lens_driver/cam_lens_driver_soc.o

spectra_camx-$(CONFIG_SPECTRA_SENSOR_SYSFS_UTIL) += \
	camera_kt/drivers/cam_sensor_module/cam_cci/cam_cci_sysfs_util.o

spectra_camx-y += camera_kt/drivers/camera_main.o
