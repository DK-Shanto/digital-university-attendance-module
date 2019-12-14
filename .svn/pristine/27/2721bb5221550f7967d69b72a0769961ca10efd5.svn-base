<?php
include_once 'blade/view.cca.blade.inc';
include_once COMMON.'class.common.inc';
//include_once './common/class.common.cca.inc';
//include_once '/../bao/class.ccabao.inc';
?>

<div class="panel panel-default">
        <div class="panel-heading">Manage Co-currricular Activities</div>
    	<div class="panel-body">

			<div id="form">
				<form action="#" method="post" class="form-horizontal">

					<div class="form-group">

						<label class="control-label col-sm-4" for="txtQuestion"> Catagory Name: </label>
						<div class="col-sm-6">
						<?php $var='<select type="text" class="form-control" value=""  name="Category" />';

							$Result = $_CCABAO->getAllCategory();
							//building the Category options
						if($Result->getIsSuccess()){

							$Category = $Result->getResultObject();

							//$var = $var.'<option value="select">Select</option>';

					       for ($i= 0; $i < sizeof($Category); $i++) {

					       		$cat = $Category[$i];


						$var = $var.'<option value="'.$cat->getCategoryName().'" ';
						//var_dump($globalUser);
					if(isset($_GET['edit']))
					{
						if($globalUser->getCat()==$cat->getCategoryName())
						{
						$var = $var.' selected="selected" ';

						}
						//echo $globalUser->getCat();
					}


						 $var=$var.'>'.$cat->getCategoryName(); '</option>';


						}
					}

						$var = $var.'</select>';
							echo $var;

						 ?>
					</div>
				</div>

					<div class="form-group">
						<label class="control-label col-sm-4" for="Activity"> Activity Name: </label>
						<div class="col-sm-6">
						<input type="text" class="form-control"  name="Activity" placeholder="Add Activity Name......" value="<?php
					if(isset($_GET['edit'])) echo $globalUser->getActivityName();  ?>"/>
						</div>
					</div>
					<div class="form-group">
						<label class="control-label col-sm-4" for="Organizer"> Organizer: </label>
						<div class="col-sm-6">
					<?php 	$var ='<select type="text" class="form-control" value=""  name="Organizer" >';

							$Result = $_CCABAO->getAllOrganizer();
							//building the Category options
						if($Result->getIsSuccess()){

							$Organizer = $Result->getResultObject();

							//$var = $var.'<option value="select">Select</option>';

					       for ($i= 0; $i < sizeof($Organizer); $i++) {

					       		$org = $Organizer[$i];

						$var = $var.'<option value="'.$org->getOrganizerName().'"';


								if(isset($_GET['edit']) )
								{
						          		if($globalUser->getOrganizer()==$org->getOrganizerName())
						          		$var = $var.' selected="selected"';
						          }


						$var = $var.'>'.$org->getOrganizerName();'</option>';

						}
					}

						$var = $var.'</select>';
						echo $var;
						?>
						</div>
					</div>
					<div class="form-group">
						<label class="control-label col-sm-4" for="venu"> Venu: </label>
						<div class="col-sm-6">
						<input type="text" class="form-control"  name="venu" placeholder="Add Venu......" value="<?php
					if(isset($_GET['edit'])) echo $globalUser->getVenu();  ?>"/>
						</div>
					</div>
					<div class="form-group">
						<label class="control-label col-sm-4" for="Description"> Description: </label>
						<div class="col-sm-6">
						<textarea rows="10" cols="40" class="form-control"  name="Description" placeholder="Description......." value=""><?php if(isset($_GET['edit'])) echo $globalUser->getDescription();  ?>
						</textarea>
						</div>
					</div>
					<div class="form-group">
						<label class="control-label col-sm-4" for="Date"> Date: </label>
						<div class="col-sm-6">
						<input type="date" class="form-control"  name="Date" placeholder="Select Date......" value="<?php
					if(isset($_GET['edit'])) echo $globalUser->getDate();  ?>"/>

						</div>
					</div>
					<div class="form-group">
						<label class="control-label col-sm-4" for="Time"> Time: </label>
						<div class="col-sm-6">
						<input type="text" class="form-control"  name="Time" placeholder="Set Time......" value="<?php
					if(isset($_GET['edit'])) echo $globalUser->getTime();  ?>"/>
						</div>
					</div>

					 <div class="form-group">
              <div class="col-sm-offset-2 col-sm-10">

						<?php
						if(isset($_GET['edit']))
						{
							?>
							<button type="submit" value="update" name="update">update</button>
							<?php
						}
						else
						{
							?>
							<button type="submit" value="save" name="saveRQST">save</button>
							<?php
						}
						?>
			    </div>
            </div>


				</form>

			</div>
		</div>
		<div class="panel-body">

	<table class="table table-bordered">
	<?php


	$Result = $_CCABAO->getAllCCA();

	//if DAO access is successful to load all the users then show them one by one
	if($Result->getIsSuccess()){

		$CCAList = $Result->getResultObject();
	?>
		<tr>
			<th>Category</th>
			<th>Activity</th>
			<th>Organizer</th>
			<th>Venue</th>
			<th>Description</th>
			<th>Date</th>
			<th>Time</th>
		</tr>
		<?php
		for($i = 0; $i < sizeof($CCAList); $i++) {
			$CCA = $CCAList[$i];
			?>
		    <tr>


			   <td><?php echo $CCA->getCat(); ?></td>
			   <td><?php echo $CCA->getActivityName(); ?></td>
			    <td><?php echo $CCA->getOrganizer(); ?></td>
			    <td><?php echo $CCA->getVenu(); ?></td>
			    <td><?php echo $CCA->getDescription(); ?></td>
			    <td><?php echo $CCA->getDate(); ?></td>
			    <td><?php echo $CCA->getTime(); ?></td>
			    <td>
			    <a href="?edit=<?php echo $CCA->getsrl(); ?>" onclick="return confirm('sure to edit !'); " >edit</a>
			    </td>

			    <td>
			    <a href="?del=<?php echo $CCA->getsrl(); ?>" onclick="return confirm('sure to delete !'); " >delete</a>
			    </td>
		    </tr>
	    <?php

		}

	}
	else{

		echo $Result->getResultObject(); //giving failure message
	}

	?>
	</table>
	</div>

</div>
