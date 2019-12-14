<?php

include_once 'blade/view.create_product.blade.inc';
include_once COMMON.'class.common.product.inc';
include_once 'blade/view.products.blade.inc';

				// 	if (isset($_POST['add'])) {
				// 	//$target = "images/".basename($_FILES["txtAddPicture"]["name"]);
						 
						
				// }
				?>	

<style type="text/css">
	.prod-box{
		width: 200px;
		height: 300px;
		overflow: hidden;
		margin: 0 20 20 0;
		position: relative;
		float: left;
		padding: 20px 20px;
	}
	.prod-box>img{
		width: 100%;
		height: 100%;
	}
	.prod-trans{
		background: rgba(0,0,0,0.6);
		width: 100%;
		height: 100%;
		top: 0;
		left: 0;
		bottom: 0;
		right: 0;
		position: absolute;
		opacity: 0;
		transition: all .5s ease;

	}
	.prod-box:hover .prod-trans{
		opacity: 1;
		transition: all .5s ease;
	}
	.prod-feature{
		text-align: center;
		margin-top: -150px;
		transition: all .75s ease;
	}
	.prod-feature p{
		color: #00eb00;
		font-family: verdana;
	}
	.prod-box:hover .prod-feature{
		margin-top: 120px;
		transition: all .75s ease;
	}

</style>

<div id="form">



			<form method="post" class="form-horizontal" enctype="multipart/form-data">
			

				<div class="form-group">
					<input type="hidden" name="eProductID" value="<?php 
					if(isset($_POST['editProducts'])) echo $getROW->getID();  ?>">
					<label class="control-label col-sm-4" for="txtName">Name : </label>
					<div class="col-sm-6">
						<input type="text" class="form-control" id="txtName"  name="txtName" placeholder="Enter Name of the Product"  value="<?php 
					if(isset($_POST['editProducts'])) echo $getROW->getName();  ?>"/>
					</div>
				</div>

				<div class="form-group">
					<label class="control-label col-sm-4" for="txtCat">Category : </label>			
					<div class="col-sm-6">	
							    <?php
							    
							    $var = '<select name="selectedCategory" class="form-control"  id="selectedCategory" class="paymentcat" onchange="post(this.value);">';
								$Result = $_CREATE_PRODUCTBAO->getAllProductCategorys();
									//if DAO access is successful to load all the Categorys then show them one by one
								if($Result->getIsSuccess()){

									$Categorys = $Result->getResultObject();

									$var = $var;
								
							       for ($i=0; $i < sizeof($Categorys); $i++) { 
							       		
							       		$ProductCategory = $Categorys[$i];
							    
							    		$var = $var. '<option value="'.$ProductCategory->getID().'"';   			
							    		if(isset($_GET['edit']) && !strcmp($_GET['edit'],$ProductCategory->getCategory())) {
							          		$var = $var.' selected="selected"';
							          	} 			

							          	$var = $var.'>'.$ProductCategory->getCategory().'</option>';
									}

									$var = $var.'</select>';
								}
								echo $var;
								?>	
					</div>
				</div>


			

				<div class="form-group">
					<label class="control-label col-sm-4" for="txtPrice">Price : </label>
					<div class="col-sm-6">
						<input type="text" class="form-control" id="txtPrice"  name="txtPrice" placeholder="Enter Price of the Product"  value="<?php 
					if(isset($_POST['editProducts'])) echo $getROW->getPrice();  ?>"/>
					</div>
				</div>

				<div class="form-group">

					<div class="col-sm-6">
											<!--
					<label class="control-label col-sm-4" for="txtCredit">
						<input type="text" class="form-control" id="txtCredit"  name="txtCredit" placeholder="Enter Price of the Product"  value="<?php 
					//if(isset($_POST['editProducts'])) echo $getROW->getOfferedCredit();  ?>"/>
				-->
					</div>
				</div>
				<div class="form-group">
					<label class="control-label col-sm-4" for="image">Add Picture: </label>
					<div class="col-sm-6">
						<input type="file" class="form-control" id="image"  name="image"   />
					</div>
				</div>



				<div class="form-group">        
		              <div class="col-sm-offset-2 col-sm-10">
							<div class="form-group">        
              <div class="col-sm-offset-2 col-sm-10">

						<?php
						if(isset($_POST['editProducts']))
						{
							?>
							<button type="submit" name="update" onclick="return confirm('sure to update?'); ">Update</button>
							<?php
						}
						else
						{
							?>
							<button type="submit" name="add" onclick="return confirm('sure to add?'); ">Add Product</button>
							<?php
						}
						?>
				</div>
			</div>
									
						</div>
				</div>	

				
				<!-- <?php
				if(isset($_GET['txtAddPicture'])){
					$image = $_FILES['txtAddPicture']['name'];
					echo $image;
				}
				?> -->
			</form>
	</div>
	<table class="table table-bordered">
				<?php
	//search clicked and result loaded

				$ResultSearch = $_PRODUCTSBAO -> searchProductByCat();
				if(isset($ResultSearch))
				{
					if($ResultSearch->getIsSuccess()){

						$UserList = $ResultSearch->getResultObject();
					}
					else{

		echo $ResultSearch->getResultObject(); //giving failure message
			}
	
	?>
</table>
	<div id="heading-block">
	<h2>Customize Products</h2>
</div>

<?php
for($i = 0; $i < sizeof($UserList); $i++) {
	$User = $UserList[$i];
	?>
	<form method="post" class="form-horizontal" action="create_product.php?edit=<?php echo $User->getID(); ?>">
		<input type="hidden" name="pID" value="<?php echo $User->getID(); ?>">
		<div class="prod-container">


			<div class="prod-box" >
				<?php

				$temp=$User->getPicture();
				echo "<img src='./resources/img/product_images/".$temp."' border='5px'>" ?>
<!-- 
	echo "<img src='images/".$row['image']."' >"; -->

	<div class="prod-trans">
		<div class="prod-feature">

			<input type="hidden" name="productID" id="productID" value="<?php echo $User->getID(); ?>">
			<p style="color: yellow;font-weight: bold;"><?php echo $User->getName(); ?></p>
			<p style="color: #fff;font-weight: bold;">Category:
				<?php $cat = $User->getCategoryID(); 

				$Result2 = $_PRODUCTSBAO->getCategoryFromId($cat);
				if($Result2->getIsSuccess())
				{

					$paymen = $Result2->getResultObject();

					echo $paymen->getCategory();
				}
				?>

			</p>
			<p style="color: #fff;font-weight: bold;">Price: <?php echo $User->getPrice(); ?></p>
			<p style="color: #fff;font-weight: bold;">Credit: <?php echo $User->getOfferedCredit(); ?></p>
			<input type="submit" name="editProducts" value="Edit" onclick="return confirm('sure to edit?? '); ">
			<input type="submit" name="deleteProduct" value="Delete" onclick="return confirm('sure to delete?? '); ">

		</div>

	</div>

</div>
</div>
</form>


<?php
}}
?>



			
			

			