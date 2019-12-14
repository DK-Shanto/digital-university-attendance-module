<?php


include_once 'blade/view.checkout.blade.inc';

include_once COMMON.'class.common.inc';

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

<?php
		$ResultTotal = $_CheckoutBAO->getPayCredit();

		if(isset($ResultTotal))
	{
//if DAO access is successful to load all the users then show them one by one
		if($ResultTotal->getIsSuccess()){

			$UserList = $ResultTotal->getResultObject();
		}
		else{
			echo $ResultTotal->getResultObject(); //giving failure message
		}
	?>
<form method="post" class="form-horizontal">
	<!--
<div>
<label style="color:red; background-color: rgba(0,0,0,1); float: right; font-size: 20px; margin-left: auto;margin-right: 0">Total Credit: <?php echo $UserList->getTotalCredit(); ?> </label></div>
<div>
-->
<label  style="color:red; background-color: rgba(0,0,0,1); float: left; font-size: 20px; margin-left: auto;margin-right: 0">Total to Pay: <?php echo $UserList->getTotalToPay(); ?></label></div><br><br>

	<input type="submit" name="commit" value="Commit" onclick="return confirm('sure to purchase?'); " style="color:green;font-weight: bolder; background-color: rgba(0,0,0,1); float: right; font-size: 22px" >
	<input type="hidden" name="totalToPay" id="totalToPay" value="<?php echo $UserList->getTotalToPay(); ?>">
	<input type="hidden" name="totalCredit" id="totalCredit" value="<?php echo $UserList->getTotalCredit(); ?>">
</form>

<?php 
} 
?>

<?php
	$ResultSearch = $_CheckoutBAO->getCartItems();
	//search clicked and result loaded
	if(isset($ResultSearch))
	{
//if DAO access is successful to load all the users then show them one by one
		if($ResultSearch->getIsSuccess()){

			$UserList = $ResultSearch->getResultObject();
		}
		else{
			echo $ResultSearch->getResultObject(); //giving failure message
		}
	
	

	?>


<div>
<div id="heading-block">
	<h2>Cart Items:</h2>
</div>


<?php
for($i = 0; $i < sizeof($UserList); $i++) {
	$User = $UserList[$i];
	?>
	<form method="post" class="form-horizontal">
		<div class="prod-container">


			<div class="prod-box" border="5">
				<?php

				$temp=$User->getPicture();

				 echo "<img src='./resources/img/product_images/".$temp."' border='5px'>" ?>
					<div class="prod-trans">
						<div class="prod-feature">

						<input type="hidden" name="productID" id="productID" value="<?php echo $User->getID(); ?>">
						<p style="color: yellow;font-weight: bold;"><?php echo $User->getName(); ?></p>		
						<p style="color: #fff;font-weight: bold;">Price: <?php echo $User->getPrice(); ?></p>
				<!--
						<p style="color: #fff;font-weight: bold;">Credit: <?php echo $User->getOfferedCredit(); ?></p>
					-->
						<input type="submit" name="deleteFromCart" value="Delete From Cart">


						<!--  <input type="hidden" name="productID" id="productID" value="<?php echo $User->getID(); ?>"> 
						<p style="color: yellow;font-weight: bold;">\Name</p>		
						<p style="color: #fff;font-weight: bold;">Price:</p>
						<p style="color: #fff;font-weight: bold;">Credit></p>
						<input type="submit" name="addToCart" value="Add to Cart"> -->

						</div>

	</div>

</div>
</div>
</form>


<?php
}
}
?>


</div>
