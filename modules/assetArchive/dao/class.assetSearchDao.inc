<!--Search specific Asset-->
<?php
// write dao object for each class
include_once COMMON.'class.common.asset.inc';
include_once UTILITY.'class.util.inc';

Class SearchAssetDao
{
    private $_DB;
    private $_Asset;

    public function __construct()
    {
        $this->_DB=DBUtil::getInstance();
        $this->_Asset=new Asset();
    }

    //Get Searched Asset
    public function getSearchedAsset(){
       
        $Type=$SerialNumber=$ModelNumber=$Brand=$Cost="";

        if (isset($_POST['Type'])){
            $Type=$_POST['Type'];
        }
        if (isset($_POST['SerialNumber'])){
            $SerialNumber=$_POST['SerialNumber'];
        }
        if (isset($_POST['ModelNumber'])){
            $ModelNumber=$_POST['ModelNumber'];
        }
        if (isset($_POST['Brand'])){
            $Brand=$_POST['Brand'];
        }
        if (isset($_POST['Status'])){
            $Cost=$_POST['Status'];
        }
        if (isset($_POST['Cost'])){
            $Cost=$_POST['Cost'];
        }


        $AssetList=array();

                 $SQL="SELECT DISTINCT ( 'id', 'type_id', 'serialNo','modelNo', 'brand', 'purchaseDate', 'status', 'configuration', 'stuff_id', 'purchasedFrom', 'cost', 'warrantyLimit') FROM 'ams_asset' WHERE 'type_id' = '%Type%', 'serialNo' = '%SerialNumber%', 'modelNo' = '%ModelNumber%', 'brand' = '%Brand%', 'status' = '%Status%', 'cost' = '%Cost%'";
        

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

}
?>
