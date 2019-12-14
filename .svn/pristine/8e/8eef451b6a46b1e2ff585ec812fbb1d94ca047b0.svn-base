<?php

include_once 'blade/view.applied_scholarship.blade.inc';
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

<?php
if(isset($_GET['seecv'])){
?>
<div class="panel panel-default">
    
    <div class="panel-heading " style="text-align: center;" ><h2>Student CV Information</h2></div>
    		<div class="container-fluid" style="background-color:#A2DA93;">
    				
    				<div class="row">
    					<div class="col-sm-4"></div>
    					<div class="col-sm-4">
    						<img style="margin-left: 86px; margin-top: 30px;" src="<?php echo './resources/img/scholarship/images/'.$globalStudent->getPicSource() ; ?>" alt="Icon" height="220" width="200" >
    					</div>
    					
    				</div>

					  
					  <br>
		
					  <div class="row">

					      <div class="row" id="attribute">
					      		<div class="col-sm-4">
							      
						    </div>
						    <div class="col-sm-4">
						    <ul class="list-group">
						      <li class="list-group-item active">Student ID : <?php echo $userPositions->getUniversityID(); ?></li>
						      <li class="list-group-item active">Student Name : <?php echo $userPositions->getFirstName()." ".$userPositions->getMiddleName()." ".$userPositions->getLastName(); ?></li>	
							  <li class="list-group-item active">Discipline : <?php echo $userPositions->getDiscipline()->getName(); ?></li>
							  <li class="list-group-item active">Email : <?php echo $userPositions->getEmail(); ?></li>
							  <li class="list-group-item active">Father's Name : <?php echo $userDetails->getFatherName(); ?></li>
							  <li class="list-group-item active">Mother's Name : <?php echo $userDetails->getMotherName(); ?></li>
							  <li class="list-group-item active">Present Address : <?php echo $userDetails->getCurrentAddress(); ?></li>
							  <li class="list-group-item active">Permanent Address : <?php echo $userDetails->getPermanentAddress(); ?></li>
							  <li class="list-group-item active">Contact No : <?php echo $userDetails->getMobilePhone(); ?></li>
							  <li class="list-group-item">Age : <?php echo $globalStudent->getAge(); ?></li>
							  <li class="list-group-item">Father's Proffession : <?php echo $globalStudent->getFatherProf(); ?></li>
							  <li class="list-group-item">Mother's Proffession : <?php echo $globalStudent->getMotherProf(); ?></li>
							  <li class="list-group-item">Yearly Income : <?php echo $globalStudent->getIncome(); ?></li>
							  <li class="list-group-item">Siblings : <?php echo $globalStudent->getSibling(); ?></li>
							  <li class="list-group-item">Year-Term : <?php echo $globalStudent->getCurrentTerm(); ?></li>
							  <li class="list-group-item">Reason For Apply : <?php echo $globalStudent->getReason(); ?></li>
							  <li class="list-group-item">Cocurricular Activity : <?php echo $globalStudent->getCocurricular(); ?></li>
							  <li class="list-group-item">Quota : <?php echo $globalStudent->getQuota();  ?></li>
							  <li class="list-group-item">Average CGPA : <?php echo $globalStudent->getCgpa(); ?></li>
							  <li class="list-group-item"><p>Parent's Contact No : <?php echo $userDetails->getMobilePhone(); ?></p></li>
							  <li class="list-group-item"><p>Document : <a href="<?php echo './resources/img/scholarship/documents/'.$globalStudent->getDocument() ; ?>">Additional File</a></p></li>

							</ul>
							    
							  	
							<form method="post" class="form-horizontal">

								<div class="form-group">
									<button type="submit" value="edit" name="edit" style="margin-left: 100px;">Edit</button>
								</div>
								
							</form>
						</div>
							    
					    <div class="col-sm-4">
					      
					    </div>
					   
					  </div> 
					  <div class="row">
					  	
					  </div>
			  </div>  

					  
		</div>
	</div>

<?php
}
?>




<?php
if(!isset($_GET['seemore']) && !isset($_POST['updatePriority']) && !isset($_GET['approveu']) && !isset($_GET['rejectu'])){
?>


<div class="panel panel-default">
    
    <div class="panel-heading">Applied Scholarship Information</div>
    
    <div class="panel-body">

	<div id="form">
		<form method="post" class="form-horizontal">
				<div class="form-group">
              	<label class="control-label col-sm-2" for="txtName">Search Name:</label>
              	<div class="col-sm-10">
					<input type="text" name="txtName" placeholder="Catagory Name" value="<?php 
					if(isset($_GET['edit'])) echo $globalCatagory->getCatagoryName();  ?>" />
				</div>				
				</div>
				<div>
				<label class="control-label col-sm-2" for="txtShortCode">Search By Category:</label>
				<div class="col-sm-10">
					<input type="text" name="txtShortCode" placeholder="Short code name" value="<?php 
					if(isset($_GET['edit'])) echo $globalCatagory->getShortName();  ?>" />
				</div>
				</div>
		        

		</form>

	</div>
	</div>

	<div class="panel-body">

	<table class="table table-bordered">
	<?php
	
	
	$Result = $_AppliedScholarshipBAO->getAllAppliedScholarships();

	//if DAO access is successful to load all the AppliedScholarships then show them one by one
	if($Result->getIsSuccess()){

		$AppliedScholarshipList = $Result->getResultObject();
	?>
		<tr>
			<th>Scholarship Title</th>
			<th>Category</th>
			<th>Last Date of Application</th>
			<th>Application Submitted</th>
		</tr>
		<?php
		for($i = 0; $i < sizeof($AppliedScholarshipList); $i++) {
			$AppliedScholarship = $AppliedScholarshipList[$i];
			?>
		    <tr>
			    <td><?php echo $AppliedScholarship->getTitle(); ?></td>
			    <td><?php echo $AppliedScholarship->getCategory(); ?></td>
			    <td><?php echo $AppliedScholarship->getLastDateOfApplication(); ?></td>
			    <td><?php echo $AppliedScholarship->getNumOfStudents(); ?></td>
			    <td><a href="?seemore=<?php echo $AppliedScholarship->getID(); ?>" onclick="return confirm('sure to see more !'); " >see more</a></td>
			    <td><a href="?del=<?php echo $AppliedScholarship->getID(); ?>" onclick="return confirm('sure to delete !'); " >delete</a></td>
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

<?php
}

else{
?>

<div class="panel panel-default">

<div class="panel-heading " style="text-align: center;" ><h2>Scholarship Details And Applicants</h2></div>


<div class="panel-body">
	
	<div class="row">
		<div class="col-sm-1"></div>
		<div class="col-sm-10">

			<br><br>
			<div class="container-fluid" style="background-color:#E1E2E6;">
				<div class="row" style="text-align: center;"><h3>Scholarship Information</h3></div>
				<div class="row">
					<div class="col-sm-10">
						<h3><?php echo $globalScholarship->getTitle(); ?></h3>
					</div>
					
				</div>

				  
				  <br>
				  <div class="row" id="attribute">
				      <p><?php echo $globalScholarship->getSubtitle(); ?></p>
				  </div> 
				  <div class="row">

				      <div class="row" id="attribute">
						    <div class="col-sm-4">
						      <p>Category : <?php echo $globalScholarship->getCategory(); ?></p>
						    </div>
						    <div class="col-sm-4">
						      <p>Organization : <?php echo $globalScholarship->getOrganization(); ?></p>
						    </div>
						    <div class="col-sm-4">
						      <p>Contact No : <?php echo $globalScholarship->getContactNumber(); ?></p>
						    </div>
						   
						  </div> 
				  </div>  

				  <div class="row">
				      <div class="row" id="attribute">
						     <div class="col-sm-4">
						      <p>Age limit : <?php echo $globalScholarship->getAgeLimit(); ?></p>
						    </div>
						    <div class="col-sm-4">
						      <p>Posted Date : <?php echo $globalScholarship->getPublishDate(); ?></p>
						    </div>
						    <div class="col-sm-4">
						      <p>Email : <?php echo $globalScholarship->getEmail(); ?></p>
						    </div>
						    
						  </div> 
				  </div>  

				  <div class="row">
				      <div class="row" id="attribute">
				      		
						    <div class="col-sm-4">
						      <p>Eligible Gender : <?php echo $globalScholarship->getGender(); ?></p>
						    </div>
						     <div class="col-sm-4">
						      <p>Amount : <?php echo $globalScholarship->getScholarshipAmount(); ?></p>
						    </div>
						    <div class="col-sm-4">
						      <p>Last Date of Application : <?php echo $globalScholarship->getLastDateOfApplication(); ?></p>
						    </div>
				    </div>
				  </div> 


			</div>
	</div>
	</div>
</div>


<div class="panel-body">
		<table class="table table-bordered">
			<?php

			$Result = $_StudentHasScholarshipBAO->getAllUsersByScholarshipId($Scholarship);
			//$Result1 = $_StudentHasScholarshipBAO->getAllUserPositionsByScholarshipId($Scholarship);
			//$Result2 = $_StudentHasScholarshipBAO->getAllUserDetailsByScholarshipId($Scholarship);

			//if DAO access is successful to load all the users then show them one by one
			if($Result->getIsSuccess()){

				$UserList = $Result->getResultObject();
				//var_dump($StudentList);
			?>
				<tr>
					<th>University ID</th>
					<th>Email</th>
					<th>First Name</th>
					<th>Middle Name</th>
					<th>Last Name</th>
					<th>Discipline</th>
					<th>Status</th>
					<th>Priority</th>
					<th>Update Priority</th>
				</tr>
				<?php
				for($i = 0; $i < sizeof($UserList); $i++) {
					$User = $UserList[$i];
					?>
				    <tr>
					    <td><?php echo $User->getUniversityID(); ?></td>
					    <td><?php echo $User->getEmail(); ?></td>
					    <td><?php echo $User->getFirstName(); ?></td>
					    <td><?php echo $User->getMiddleName(); ?></td>
					    <td><?php echo $User->getLastName(); ?></td>
					    <td><?php echo $User->getDiscipline(); ?></td>
					    <td><?php echo $User->getStatus(); ?></td>
					    <td><?php echo $User->getPriority(); ?></td>
					    <td>
					    	<form action="?uu=<?php echo $User->getUniversityID(); ?>&us=<?php echo $globalScholarship->getID(); ?>" method="post" class="form-horizontal">

								<div class="form-group">
					              	<div class="col-sm-5">
					              		<input type="text" name="txtPriority" class="form-control" placeholder="Enter Priority" required/>
										
								  	</div>
								  	<div class="col-sm-7">
								  		<button type="submit" value="updatePriority" name="updatePriority">update</button>
								  	
								  	</div>
								</div>
							</form>	
					    </td>
					    <td>
					    <a href="?seecv=<?php echo $User->getUniversityID(); ?>" onclick="return confirm('sure to see cv !'); " >see cv</a>
					    </td>
					    <td>
					    <a href="?approveu=<?php echo $User->getUniversityID(); ?>&approves=<?php echo $globalScholarship->getID(); ?>" onclick="return confirm('sure to approve !'); ">approve</a>
						</td>
						<td>
					    <a href="?rejectu=<?php echo $User->getUniversityID(); ?>&rejects=<?php echo $globalScholarship->getID(); ?>" onclick="return confirm('sure to reject !'); ">reject</a>
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
<?php	
}
?>
