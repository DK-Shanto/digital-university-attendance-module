<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_ASSET.'dao/class.receiveRepairDao.inc';

/*
	User Business Object
*/
Class ReceiveRepairBao
{

    private $_ReceiveRepairDao;

    function __construct()
    {
        $this->_ReceiveRepairDao=new ReceiveRepairDao();

    }

    public function getRepairByAssetSerialNo($Asset){
        $Result=$this->_ReceiveRepairDao->getRepairByAssetSerialNo($Asset);

        if (!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ReceiveRepairDao.getRepairByAssetSerialNo($Asset)");
        }

        return $Result;
    }

    public function receiveRepair($Repair){
        $Result=$this->_ReceiveRepairDao->receiveRepair($Repair);

        if (!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ReceiveRepairDao.receiveRepair($Repair)");
        }

        return $Result;
    }

    public function getAllRepair(){
        $Result=$this->_ReceiveRepairDao->getAllRepair();

        if (!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ReceiveRepairDao.getAllRepair()");
        }

        return $Result;
    }

    public function getRepairById($Repair){
        $Result=$this->_ReceiveRepairDao->getRepairById($Repair);

        if (!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ReceiveRepairDao.getRepairById($Repair)");
        }

        return $Result;
    }

    public function updateRepair($Repair){
        $Result=$this->_ReceiveRepairDao->updateRepair($Repair);

        if (!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ReceiveRepairDao.updateRepair($Repair)");
        }

        return $Result;
    }

    public function deleteRepair($Repair){
        $Result=$this->_ReceiveRepairDao->deleteRepair($Repair);

        if (!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ReceiveRepairDao.deleteRepair($Repair)");
        }

        return $Result;
    }

}
