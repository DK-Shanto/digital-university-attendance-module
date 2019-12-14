<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_ASSET.'dao/class.assetDetailsDao.inc';

/*
	User Business Object
*/
Class AssetDetailsBao
{

    private $_AssetDetailsDao;

    function __construct()
    {
        $this->_AssetDetailsDao = new AssetDetailsDao();
    }

    public function getAsset($Asset){
        $Result=$this->_AssetDetailsDao->getAsset($Asset);

        if (!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in AssetDetailsDao.getAsset($Asset)");
        }

        return $Result;
    }

    public function getRepairByAssetId($Asset){
        $Result=$this->_AssetDetailsDao->getRepairByAssetId($Asset);

        if (!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in AssetDetailsDao.getRepairByAssetId($Asset)");
        }

        return $Result;
    }

    public function deleteRepair($Repair){
        $Result=$this->_AssetDetailsDao->deleteRepair($Repair);

        if (!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ReceiveRepairDao.deleteRepair($Repair)");
        }

        return $Result;
    }
}