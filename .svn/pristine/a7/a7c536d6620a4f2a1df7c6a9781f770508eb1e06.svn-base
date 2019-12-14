<?php
// write dao object for each class
include_once COMMON.'class.common.asset.inc';
include_once UTILITY.'class.util.inc';

Class AssetDao
{

    private $_DB;
    private $_AssetType;
    private $_Stuff;
    private $_Asset;

    function __construct()
    {
        $this->_DB = DBUtil::getInstance();
        $this->_AssetType=new AssetType();
        $this->_Stuff=new User();
        $this->_Asset=new Asset();
    }

    public function getAllAssetType(){
        $TypeList=array();
        $SQL="SELECT * FROM ams_asset_type";
        $this->_DB->doQuery($SQL);
        $rows=$this->_DB->getAllRows();
        foreach ($rows as $row) {
            $this->_AssetType=new AssetType();
            $this->_AssetType->setAssetTypeId($row['id']);
            $this->_AssetType->setAssetTypeName($row['name']);

            $TypeList[]=$this->_AssetType;
        }

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($TypeList);

        return $Result;
    }

    public function getAllStuff(){
        $StuffList=array();
        $SQL="SELECT ums_user.ID,ums_user.FirstName,ums_user.LastName FROM ums_user INNER JOIN ums_user_role ON ums_user.ID=ums_user_role.UserID
              INNER JOIN ums_role ON ums_user_role.RoleID=ums_role.ID WHERE ums_role.Name='Stuff'";
        $this->_DB->doQuery($SQL);
        $rows=$this->_DB->getAllRows();
        foreach ($rows as $row){
            $this->_Stuff=new User();
            $this->_Stuff->setID($row['ID']);
            $this->_Stuff->setFirstName($row['FirstName']);
            $this->_Stuff->setLastName($row['LastName']);

            $StuffList[]=$this->_Stuff;
        }

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($StuffList);

        return $Result;
    }

    public function createAsset($Asset){
        $ID=$Asset->getAssetId();
        $TypeID=$Asset->getAssetTypeId();
        $SerialNo=$Asset->getAssetSerialNo();
        $ModelNo=$Asset->getAssetModelNo();
        $Brand=$Asset->getAssetBrand();
        $PurchaseDate=$Asset->getAssetPurchaseDate();
        $Status=$Asset->getAssetStatus();
        $Configuration=$Asset->getAssetConfiguration();
        $StuffID=$Asset->getAssetStuffId();
        $PurchasedFrom=$Asset->getAssetPurchasedFrom();
        $Cost=$Asset->getAssetCost();
        $Warranty=$Asset->getAssetWarrantyLimit();

        $SQL="INSERT INTO ams_asset VALUES ('$ID','$TypeID','$SerialNo','$ModelNo','$Brand','$PurchaseDate','$Status',
             '$Configuration','$StuffID','$PurchasedFrom','$Cost','$Warranty')";

        $SQL=$this->_DB->doQuery($SQL);

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($SQL);

        return $Result;
    }

    public function getAllAsset(){
        $AssetList=array();
        $SQL="SELECT * FROM ams_asset";
        $this->_DB->doQuery($SQL);
        $rows=$this->_DB->getAllRows();
        foreach ($rows as $row) {
            $this->_Asset=new Asset();
            $this->_Asset->setAssetId($row['id']);
            $this->_Asset->setAssetTypeId($row['type_id']);
            $this->_Asset->setAssetSerialNo($row['serialNo']);
            $this->_Asset->setAssetModelNo($row['modelNo']);
            $this->_Asset->setAssetBrand($row['brand']);
            $this->_Asset->setAssetPurchaseDate($row['purchaseDate']);
            $this->_Asset->setAssetStatus($row['status']);
            $this->_Asset->setAssetConfiguration($row['configuration']);
            $this->_Asset->setAssetStuffId($row['stuff_id']);
            $this->_Asset->setAssetPurchasedFrom($row['purchasedFrom']);
            $this->_Asset->setAssetCost($row['cost']);
            $this->_Asset->setAssetWarrantyLimit($row['warrantyLimit']);

            $AssetList[]=$this->_Asset;
        }

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($AssetList);

        return $Result;
    }

    public function getTypeById($Type){
        $SQL="SELECT * FROM ams_asset_type WHERE ams_asset_type.id='".$Type."'";
        $this->_DB->doQuery($SQL);
        $row=$this->_DB->getTopRow();
        $this->_AssetType=new AssetType();
        $this->_AssetType->setAssetTypeId($row['id']);
        $this->_AssetType->setAssetTypeName($row['name']);

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($this->_AssetType);

        return $Result;
    }

    public function getStuffById($Stuff){
        $SQL="SELECT * FROM ums_user WHERE ums_user.ID='".$Stuff."'";
        $this->_DB->doQuery($SQL);
        $row=$this->_DB->getTopRow();
        $this->_Stuff=new User();
        $this->_Stuff->setID($row['ID']);
        $this->_Stuff->setFirstName($row['FirstName']);
        $this->_Stuff->setLastName($row['LastName']);

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($this->_Stuff);

        return $Result;
    }

    public function getAssetById($Asset){
        $SQL="SELECT * FROM ams_asset WHERE ams_asset.id='".$Asset->getAssetId()."'";
        $this->_DB->doQuery($SQL);
        $row=$this->_DB->getTopRow();
        $this->_Asset=new Asset();
        $this->_Asset->setAssetId($row['id']);
        $this->_Asset->setAssetTypeId($row['type_id']);
        $this->_Asset->setAssetSerialNo($row['serialNo']);
        $this->_Asset->setAssetModelNo($row['modelNo']);
        $this->_Asset->setAssetBrand($row['brand']);
        $this->_Asset->setAssetPurchaseDate($row['purchaseDate']);
        $this->_Asset->setAssetStatus($row['status']);
        $this->_Asset->setAssetConfiguration($row['configuration']);
        $this->_Asset->setAssetStuffId($row['stuff_id']);
        $this->_Asset->setAssetPurchasedFrom($row['purchasedFrom']);
        $this->_Asset->setAssetCost($row['cost']);
        $this->_Asset->setAssetWarrantyLimit($row['warrantyLimit']);

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($this->_Asset);

        return $Result;

    }

    public function updateAsset($Asset){
        $SQL="UPDATE ams_asset SET ams_asset.type_id='".$Asset->getAssetTypeId()."',ams_asset.serialNo='".$Asset->getAssetSerialNo()."',
        ams_asset.modelNo='".$Asset->getAssetModelNo()."',ams_asset.brand='".$Asset->getAssetBrand()."',ams_asset.purchaseDate='".$Asset->getAssetPurchaseDate()."',
        ams_asset.status='".$Asset->getAssetStatus()."',ams_asset.configuration='".$Asset->getAssetConfiguration()."',ams_asset.stuff_id='".$Asset->getAssetStuffId()."',
        ams_asset.purchasedFrom='".$Asset->getAssetPurchasedFrom()."',ams_asset.cost='".$Asset->getAssetCost()."',ams_asset.warrantyLimit='".$Asset->getAssetWarrantyLimit()."'
        WHERE ams_asset.id='".$Asset->getAssetId()."'";

        $SQL=$this->_DB->doQuery($SQL);

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($SQL);

        return $Result;
    }

    public function deleteAsset($Asset){
        $SQL="DELETE FROM ams_asset WHERE ams_asset.id='".$Asset->getAssetId()."'";

        $SQL=$this->_DB->doQuery($SQL);

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($SQL);

        return $Result;
    }
}