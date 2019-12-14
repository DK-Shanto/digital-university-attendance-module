<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_ASSET.'dao/class.sendRepairDao.inc';

/*
	User Business Object
*/
Class SendRepairBao
{

    private $_SendRepairDao;

    function __construct()
    {

        $this->_SendRepairDao = new SendRepairDao();

    }

    public function getAssetIdBySerialNo($Asset){
        $Result=$this->_SendRepairDao->getAssetIdBySerialNo($Asset);

        if (!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in SendRepairDao.getAssetIdBySerialNo($Asset)");
        }

        return $Result;
    }

    public function sendRepair($Repair){
        $Result=$this->_SendRepairDao->sendRepair($Repair);

        if (!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in SendRepairDao.sendRepair($Repair)");
        }

        return $Result;
    }

    public function getAllRepair(){
        $Result=$this->_SendRepairDao->getAllRepair();

        if (!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in SendRepairDao.getAllRepair()");
        }

        return $Result;
    }

    public function getRepairById($Repair){
        $Result=$this->_SendRepairDao->getRepairById($Repair);

        if (!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in SendRepairDao.getRepairById($Repair)");
        }

        return $Result;
    }

    public function updateRepair($Repair){
        $Result=$this->_SendRepairDao->updateRepair($Repair);

        if (!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in SendRepairDao.updateRepair($Repair)");
        }

        return $Result;
    }

    public function deleteRepair($Repair){
        $Result=$this->_SendRepairDao->deleteRepair($Repair);

        if (!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in SendRepairDao.deleteRepair($Repair)");
        }

        return $Result;
    }
}