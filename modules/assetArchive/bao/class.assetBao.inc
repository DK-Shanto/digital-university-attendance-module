<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_ASSET.'dao/class.assetDao.inc';

/*
	User Business Object
*/
Class AssetBao
{

    private $_AssetDao;

    function __construct()
    {

        $this->_AssetDao = new AssetDao();

    }

    public function getAllAssetType(){
        $Result=$this->_AssetDao->getAllAssetType();

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in AssetDao.getAllAssetType()");
        }

        return $Result;
    }

    public function getAllStuff(){
        $Result=$this->_AssetDao->getAllStuff();

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in AssetDao.getAllStuff()");
        }

        return $Result;
    }

    public function createAsset($Asset){
        $Result=$this->_AssetDao->createAsset($Asset);

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in AssetDao.createAsset($Asset)");
        }

        return $Result;
    }

    public function getAllAsset(){
        $Result=$this->_AssetDao->getAllAsset();

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in AssetDao.getAllAsset()");
        }

        return $Result;
    }

    public function getTypeById($Type){
        $Result=$this->_AssetDao->getTypeById($Type);

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in AssetDao.getTypeById($Type)");
        }

        return $Result;
    }

    public function getStuffById($Stuff){
        $Result=$this->_AssetDao->getStuffById($Stuff);

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in AssetDao.getStuffById($Stuff)");
        }

        return $Result;
    }

    public function getAssetById($Asset){
        $Result=$this->_AssetDao->getAssetById($Asset);

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in AssetDao.getAssetById($Asset)");
        }

        return $Result;
    }

    public function updateAsset($Asset){
        $Result=$this->_AssetDao->updateAsset($Asset);

        if (!$Result->getIsSuccess()){
            $Result->setResultObject('Database failure in AssetDao.updateAsset($Asset)');
        }

        return $Result;
    }

    public function deleteAsset($Asset){
        $Result=$this->_AssetDao->deleteAsset($Asset);

        if (!$Result->getIsSuccess()){
            $Result->setResultObject('Database failure in AssetDao.deleteAsset($Asset)');
        }

        return $Result;
    }
}