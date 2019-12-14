<?php

include_once 'blade/view.achieved_scholarship.blade.inc';
include_once COMMON.'class.common.inc';
?>

<style type="text/css">
	#attribute{
		margin-left: 4px;
	}

	#btnApply{
		padding: 7px 29px; margin-left: 28px; margin-top: 14px;
	}
</style>

<div class="panel panel-default">
	<?php
	if ($flag==false){ 
	?>
    <div class="panel-heading " style="text-align: center; background-color: #C9302C" ><h2>You aren't selected for any scholarship.</h2></div>
    <?php
	}


    else{
    ?>
    <div class="panel-heading " style="text-align: center; background-color: #449D44" ><h2>Congratulations! You have got Scholarships.</h2></div>
    <div class="panel-body">
    	
    	<div class="row">
    		<div class="col-sm-1"></div>
    		<div class="col-sm-10">
    		<?php


			
			

    		for($i=0; $i<sizeof($StudentHasScholarshipList); $i++){ 
    			$StudentHasScholarship = $StudentHasScholarshipList[$i];
    			$globalScholarship = new Scholarship();
    			$globalScholarship->setID($StudentHasScholarship->getScholarshipID());

    			$Result = $_ScholarshipBAO->readScholarship($globalScholarship);

				//if DAO access is successful to load all the users then show them one by one
				if($Result->getIsSuccess()){

					$Scholarship = $Result->getResultObject();
				

	    		?>
	    		
	    			<br><br>
	    			<div class="container-fluid" style="background-color:#E1E2E6;">
	    				<div class="row">
	    					<div class="col-sm-10">
	    						<h3><?php echo $Scholarship->getTitle(); ?></h3>
	    					</div>
	    					
	    				</div>

						  
						  <br>
						  <div class="row" id="attribute">
						      <p><?php echo $Scholarship->getSubtitle(); ?></p>
						  </div> 
						  <div class="row">

						      <div class="row" id="attribute">
								    <div class="col-sm-3">
								      <p>Category : <?php echo $Scholarship->getCategory(); ?></p>
								    </div>
								    <div class="col-sm-3">
								      <p>Organization : <?php echo $Scholarship->getOrganization(); ?></p>
								    </div>
								    <div class="col-sm-3">
								      <p>Contact No : <?php echo $Scholarship->getContactNumber(); ?></p>
								    </div>
								   
								  </div> 
						  </div>  

						  <div class="row">
						      <div class="row" id="attribute">
								     <div class="col-sm-3">
								      <p>Age limit : <?php echo $Scholarship->getAgeLimit(); ?></p>
								    </div>
								    <div class="col-sm-3">
								      <p>Posted Date : <?php echo $Scholarship->getPublishDate(); ?></p>
								    </div>
								    <div class="col-sm-3">
								      <p>Email : <?php echo $Scholarship->getEmail(); ?></p>
								    </div>
								    
								  </div> 
						  </div>  

						  <div class="row">
						      <div class="row" id="attribute">
						      		
								    <div class="col-sm-3">
								      <p>Eligible Gender : <?php echo $Scholarship->getGender(); ?></p>
								    </div>
								     <div class="col-sm-3">
								      <p>Amount : <?php echo $Scholarship->getScholarshipAmount(); ?></p>
								    </div>
								    <div class="col-sm-3">
								      <p>Last Date of Application : <?php echo $Scholarship->getLastDateOfApplication(); ?></p>
								    </div>
						    </div>
						  </div> 


					</div>
				
				<?php } 
				
				else{

					echo $Result->getResultObject(); //giving failure message
				}
			}

			?>
			</div>		
    		<div class="col-sm-1"></div>
    	</div>
	</div>
	<?php
	}
	?>

</div>