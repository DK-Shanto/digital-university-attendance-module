<?php


include_once 'blade/view.products.blade.inc';
include_once 'blade/view.create_product.blade.inc';
include_once COMMON.'class.common.inc';

?>
<head>
	<link rel="stylesheet" href="../resources/css/style.css">
</head>


<!-- this is for styling the products -->

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
<!-- styling of the product end here -->
<div>
		<a style="color:red; background-color: rgba(0,0,0,.6); float: right; font-size: 28px" href="./checkout.php">Check Out</a>
</div>

<div id="form">
	<!-- <form method="post" class="form-horizontal">

		<label class="col-sm-2" for="txtSearch">Search By : </label><br>	
		


		<label class="col-sm-1" for="txtCat">Category:  </label><br>
		<div class="col-sm-6">
			<div class="col-sm-4">	
				<?php

				$var = '<select name="selectedCategory"   id="selectedCategory" class="paymentcat" onchange="post(this.value);">';
				$Result = $_CREATE_PRODUCTBAO->getAllProductCategorys();
									//if DAO access is successful to load all the Categorys then show them one by one
				if($Result->getIsSuccess()){

					$Categorys = $Result->getResultObject();

					$var = $var.'<option selected disabled>Select Category</option>';

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
			</div><br>

			<button type="submit" name="searchByCat">Search</button><br>

		</div>



	</form>	 -->		
	<div>

		<form method="post" class="form-horizontal">
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
</form>		
</div>




</div>


<div id="heading-block">
	<h2>Products</h2>
</div>

<?php
for($i = 0; $i < sizeof($UserList); $i++) {
	$User = $UserList[$i];
	?>
	<form method="post" class="form-horizontal">
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
			<!--<p style="color: #fff;font-weight: bold;">Credit: <?php echo $User->getOfferedCredit(); ?></p>
			-->
			<input type="submit" name="addToCart" value="Add to Cart">

		</div>

	</div>

</div>
</div>
</form>


<?php
}}
?>

