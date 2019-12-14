<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_ASSET.'dao/class.assetLendDao.inc';

/*
	User Business Object
*/
Class AssetLendBao
{

    private $_AssetLendDao;

    function __construct()
    {
        $this->_AssetLendDao = new AssetLendDao();

    }

    public function lendAsset($UserAsset){
        $Result=$this->_AssetLendDao->lendAsset($UserAsset);

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in AssetLendDao.lendAsset($UserAsset)");
        }

        return $Result;
    }
}