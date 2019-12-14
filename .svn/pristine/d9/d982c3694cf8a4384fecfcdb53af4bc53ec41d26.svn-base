<?php
// write dao object for each class
include_once COMMON.'class.common.asset.inc';
include_once UTILITY.'class.util.inc';

Class AssetLendDao
{

    private $_DB;

    function __construct()
    {
        $this->_DB = DBUtil::getInstance();
    }

    public function lendAsset($UserAsset){
        $ID=$UserAsset->getUserAssetId;
        $UserId=$UserAsset->getUserAssetUserId;
        $AssetId=$UserAsset->getUserAssetAssetId;
        $LendingDate=$UserAsset->getUserAssetLendingDate;

        $SQL="INSERT INTO ams_user_asset VALUES('$ID','$UserId','$AssetId','$LendingDate')";

        var_dump($SQL);
        $SQL=$this->_DB->doQuery($SQL);

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($SQL);

        //return $Result;
    }
}